#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

/*
迭代器：迭代器可以将任意容器抽象为一个序列，可以使用迭代器来遍历容器中的元素
设计初衷是为了解决容器与算法的耦合问题，与指针类似，可以通过迭代器来访问容器中的元素
*/

template <typename T>
void printAuto(T &&t)
{
    std::cout << t << std::endl;
}

/* 打印容器的相关元素 */
void printVec(const std::vector<int> &v)
{
    std::cout << "[";
    for (const auto &e : v)
    {
        std::cout << e << " ";
    }
    std::cout << "]" << std::endl;
}

void test1()
{
    std::cout << "test1 =================================" << std::endl;
    std::vector<int> v1{1, 2, 3, 4, 5};

    // 声明一个迭代器
    std::vector<int>::iterator it = v1.begin(); // 指向容器的第一个元素
    printAuto(*it);                             // 取出迭代器指向的元素

    it++; // 迭代器指向第二个元素
    printAuto(*it);

    it += 2; // 迭代器指向第四个元素
    printAuto(*it);

    it -= 2; // 迭代器指向第二个元素
    printAuto(*it);

    it = v1.end() - 1; // 指向容器的最后一个元素 end() 返回的是一个指向容器最后一个元素的下一个位置，所以要减去1
    printAuto(*it);    // 取出迭代器指向的元素
}

void test2()
{
    std::cout << "test2 =================================" << std::endl;
    std::vector<int> v1{1, 2, 3, 4, 5};

    auto it = v1.begin(); // 使用 auto 关键字自动推导迭代器类型

    while (it != v1.end()) // 迭代器不等于容器的结束位置
    {
        printAuto(*it); // 取出迭代器指向的元素
        it++;               // 迭代器指向下一个元素
    }

    it = v1.begin(); // 重新指向容器的第一个元素

    while (it != v1.end())
    {
        *it = 100;
        it++;
    }
    printVec(v1);
}

void test3()
{
    std::cout << "test3 =================================" << std::endl;
    std::vector<int> v1{1, 2, 3, 4, 5};

    // 常量迭代器，只能读取元素，不能修改元素
    std::vector<int>::const_iterator it = v1.begin(); // 指向容器的第一个元素
    auto it2 = v1.cbegin(); // 如果用auto的话，需要使用cbegin()函数来获取常量迭代器

    while (it != v1.end()) // 迭代器不等于容器的结束位置
    {
        printAuto(*it); // 取出迭代器指向的元素
        it++;               // 迭代器指向下一个元素
    }

    it = v1.begin();
    while (it != v1.end())
    {
        // *it = 100; // 不能修改元素
        it++;
    }
}

void test4()
{
    std::cout << "test4 =================================" << std::endl;
    
    // 对不同类型的容器使用迭代器
    std::list<int> l1{1, 2, 3, 4, 5};
    auto it = l1.rbegin(); // 反向迭代器，指向容器的最后一个元素

    while (it != l1.rend()) // rend()执行第一个元素的前一个位置
    {
        printAuto(*it); // 取出迭代器指向的元素
        it++;               // 迭代器指向下一个元素
    }
}

int main()
{
    //test1();
    //test2();
    //test3();
    test4();
    return 0;
}