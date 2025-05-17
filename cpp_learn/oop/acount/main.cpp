#include <iostream>
#include <string>
#include <thread>
#include <vector>

#include "account.hpp"

Account steve_account{"steve", 1000.0};

void printInfo(Account account) { account.print(); }

Account create_super_account() {
    Account super_account{"super", 10000.0};
    return super_account; // 返回对象
}

int main() {
    // 由类创建对象
    Account jobs_account;
    Account alice_account{"alice", 1000.0}; // 带参数的构造函数

    {
        // 这里创建的对象是局部对象，离开作用域后会自动销毁，调用其析构函数
        Account local_account{"local", 1000.0};
        local_account.print();
    }

    Account *mary_account = new Account();

    Account accounts[]{jobs_account, alice_account}; // 数组
    std::vector<Account> accounts_vector{jobs_account}; // 向量
    accounts_vector.push_back(alice_account); // 向量
    accounts_vector.push_back(Account()); // 添加一个临时对象
    accounts_vector.emplace_back(); // 直接在vector中创建对象

    // 访问对象的属性和方法
    jobs_account.set_name("Steve Jobs");
    jobs_account.set_balance(1000.0);
    alice_account.set_name("Alice");
    alice_account.set_balance(2000.0);
    mary_account->set_name("Mary");
    mary_account->set_balance(3000.0);
    jobs_account.print();
    alice_account.print();
    mary_account->print();
    jobs_account.deposit(500.0);
    alice_account.withdraw(1000.0);
    mary_account->withdraw(4000.0);

    Account super_account = create_super_account(); // 返回对象

    Account bill_account{jobs_account};

    printInfo(bill_account);

    delete mary_account;
    return 0;
}
