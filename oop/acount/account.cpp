#include <iostream>
#include <string>

#include "account.hpp" // 头文件包含

// 定义Account类的构造函数
Account::Account()
    : Account{"none", 0} {}

Account::Account(std::string name)
    : Account{name, 0} {}

Account::Account(std::string name, double balance)
    : name(name), balance(balance) {}

// 析构函数
Account::~Account()
{
    std::cout << "析构函数: Account " << this->name << " is destroyed" << std::endl; // 析构时输出账户名称
}

void Account::set_name(std::string name) // 设置账户名称
{
    this->name = name; // this是一个指向当前对象的指针
}
void Account::set_balance(double balance) // 设置账户余额
{
    this->balance = balance;
}
std::string Account::get_name() // 获取账户名称
{
    return this->name;
}
double Account::get_balance() // 获取账户余额
{
    return this->balance;
}

void Account::print() // 打印账户信息
{
    std::cout << "Account name: " << this->name << std::endl;
    std::cout << "Account balance: " << this->balance << std::endl;
}

bool Account::deposit(double amount) // 存款
{
    if (amount < 0)
    {
        std::cout << "Invalid deposit amount" << std::endl;
        return false;
    }
    this->balance += amount;
    std::cout << "Deposited: " << amount << std::endl;
    return true;
}

bool Account::withdraw(double amount) // 取款
{
    if (amount < 0 || amount > balance)
    {
        std::cout << "Invalid withdraw amount" << std::endl;
        return false;
    }
    this->balance -= amount;
    std::cout << "Withdrawn: " << amount << std::endl;
    return true;
}

// 拷贝构造函数
// 使用初始化列表的方式
// Account::Account(const Account &source)
//     : name{source.name}, balance{source.balance}
// {
//     std::cout << "拷贝构造函数: Account " << this->name << " 被调用 " << std::endl;
// }

// 使用代理构造函数的方式
Account::Account(const Account &source)
    : Account{source.name, source.balance} // 代理构造函数
{
    std::cout << "拷贝构造函数: Account " << this->name << " 被调用 " << std::endl;
}