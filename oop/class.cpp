#include <iostream>
#define DEBUG 0


class Account
{
    // 属性
    std::string name;
    double balance;

    // 方法
    bool deposit(double amount); // 存款
    bool withdraw(double amount); // 取款

};

int main()
{
    int num {10};
    std::cout << "num: " << num << std::endl;
    return 0;
}