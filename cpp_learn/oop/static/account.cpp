#include <iostream>
#include <string>

class Account
{
private:
    // 属性
    std::string name{"None"};
    double balance{0.0};
    static int account_count; // 静态成员变量，所有对象共享，不能在类里面初始化

public:
    
    static int get_account_count(); // 访问静态成员变量的函数
    Account(std::string name, double balance);
    ~Account();
};

// 在类外初始化静态成员变量
int Account::account_count = 0;

Account::Account(std::string name, double balance)
    : name{name}, balance{balance}
{
    this->account_count++;
    std::cout << "创建一个新的成员，名称为：" << this->name << "，数量加一，当前为：" << this->account_count << std::endl;
}

Account::~Account()
{
    this->account_count--;
    std::cout << "销毁一个成员，名称为：" << this->name << "，数量减一，当前为：" << this->account_count << std::endl;
}

int Account::get_account_count() // 定义的时候不用再加static
{
    // 静态成员函数只能访问静态成员变量
    return account_count;
}

int main()
{
    // 直接访问静态成员变量，一般不会这样访问，静态成员变量一般在private中，需要在public中提供访问函数
    // std::cout << "当前已有账户数量：" << Account::account_count <<std::endl;
    Account jobs("jobs", 100.0);

    // 静态成员函数可以在不创建对象的情况下直接被调用
    std::cout << "当前已有账户数量：" << Account::get_account_count() << std::endl;
    Account alice("alice", 200.0);

    return 0;
}