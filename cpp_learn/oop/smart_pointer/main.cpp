#include <iostream>
#include <memory>
#include <vector>

#include "account.hpp"

/*
智能指针：
一般指向heap中的内存
智能指针是一个类模板，提供了对动态分配内存的管理功能，对原始指针做了一层封装

三种常见的智能指针：
1. std::unique_ptr：独占式智能指针，不能被复制，只能被移动，不能共享所有权
2. std::shared_ptr：共享式智能指针，可以被多个指针共享，引用计数
3. std::weak_ptr：弱引用智能指针，不能拥有对象的所有权，不能直接访问对象，必须通过std::shared_ptr来访问

unique_ptr:
unique_ptr<T> ptr_name 多个unique_ptr不能指向同一块内存，拥有指向对象的唯一所有权，不可以复制或赋值，但可以移动
*/

int main()
{
    std::unique_ptr<int> p1{new int{100}};

    // 使用智能指针，和一般指针一样
    std::cout << "p1: " << *p1 << std::endl; // 解引用
    *p1 = 200;                               // 修改值
    std::cout << "p1: " << *p1 << std::endl; // 解引用

    std::unique_ptr<int> p2{new int{300}};

    std::cout << p2.get() << std::endl; // 获取原始指针，打印地址

    if (p2)
        std::cout << "p2 is not null" << std::endl; // 判断指针是否为空

    p2.reset(); // 释放内存，p2重新变为空指针

    if (p2)
        std::cout << "p2 is not null" << std::endl; // 判断指针是否为空
    else
        std::cout << "p2 is null" << std::endl; // 判断指针是否为空

    // 智能指针指向自定义类
    std::unique_ptr<Account> p3{new Account{"Tom", 1000.0}}; // 创建智能指针，指向Account对象

    // 通过智能指针，调用类的成员函数
    p3->print();      // 使用->运算符访问成员函数
    p3->deposit(500); // 存款
    p3->print();      // 打印账户信息

    // 智能指针不能拷贝或赋值，但可以移动
    std::vector<std::unique_ptr<Account>> accounts;

    // accounts.push_back(p3); // 通过拷贝的方式将account类型的智能指针添加到vector中，编译会报错
    accounts.push_back(std::move(p3)); // 通过移动的方式将account类型的智能指针添加到vector中，移交所有权

    for (const auto &account : accounts)
    {
        account->print(); // 打印账户信息
    }
    // p3->print(); // p3已经被移动，不能再使用


    // c++14引入了std::make_unique函数，简化了智能指针的创建，在堆上创建对象并返回一个unique_ptr
    auto p4 = std::make_unique<Account>("Jerry", 2000.0); // 使用std::make_unique创建智能指针，指向Account对象

    std::unique_ptr<int> p5 = std::make_unique<int>(100); // 使用std::make_unique创建智能指针，指向int对象
    std::unique_ptr<Account> p6 = std::make_unique<Account>("Tom", 1000.0); // 使用std::make_unique创建智能指针，指向Account对象

    p6->print();


    /*
    shared_ptr:
    shared_ptr<T> ptr_name; // 创建一个shared_ptr，指向T类型的对象
    也是指向heap中类型为T的对象，多个shared_ptr可以指向同一块内存，拥有指向对象的共享所有权，可以移动、复制、赋值
    销毁机制：
    引用计数，当引用计数为0时，释放内存
    shared_ptr的引用计数是线程安全的，多个线程可以同时访问同一个shared_ptr
    */

    std::cout << "--------------------------------------------" << std::endl;

    std::shared_ptr<int> p7 {new int{100}}; 
    std::cout << "p7: " << *p7 << std::endl; // 解引用

    // 打印引用计数
    std::cout << "p7 use count: " << p7.use_count() << std::endl; 

    auto p8 = p7; // 复制，引用计数加1

    std::cout << "p8 use count: " << p8.use_count() << std::endl; 

    std::shared_ptr<int> p9 {p7}; // 拷贝构造

    p8.reset(); // 释放内存，引用计数减1
    std::cout << "p9 use count: " << p9.use_count() << std::endl; 

    //make_share函数，c++11就有了
    auto p10 = std::make_shared<Account>("Tom", 1000.0); // 创建shared_ptr，指向Account对象
    p10->print(); // 打印账户信息
    accounts.at(0)->print();

    return 0;

    // 离开作用域时，智能指针会自动释放内存
}