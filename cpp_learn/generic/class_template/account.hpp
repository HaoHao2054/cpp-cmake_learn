#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>

class Account
{
public: // 可以被任何实体访问
    // 重载多个构造函数，用以不同的初始化方式
    /*
    构造函数在创建对象时自动被调用，可以重载
    析构函数在对象销毁时自动被调用，不可以重载
    */
    Account();                 // 默认构造函数
    Account(std::string name); // 带参数的构造函数
    // Account(std::string name, double balance); // 带参数的构造函数

    // 构造函数初始化列表
    /*
    等价于： 
    Account::Account(std::string name, double balance) // 带参数的构造函数
    {
    this->name = name; // 初始化账户名称
    this->balance = balance; // 初始化账户余额
    }
    */
    Account(std::string name, double balance);

    // 构造函数代理：用多个参数的构造函数调用单个参数的构造函数

    void set_name(std::string name);  // 设置账户名称
    void set_balance(double balance); // 设置账户余额
    std::string get_name();           // 获取账户名称
    double get_balance();             // 获取账户余额
    void print();                     // 打印账户信息
    bool deposit(double amount);
    bool withdraw(double amount);

    // 拷贝构造函数
    Account(const Account &account);

    // 析构函数
    ~Account();

private: // 只能被类的成员访问
    // 属性
    std::string name{"None"};
    double balance{0.0};

protected: // 可以被本类和子类（继承）的方法访问
};

#endif // ACCOUNT_HPP