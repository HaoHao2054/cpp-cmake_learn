#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "account.hpp"

/*
类模板：
类似于函数模板，类模板是一个类的蓝图，可以用来创建多个类的实例
*/

template <typename T>
class Item
{
private:
    std::string name;
    T value;

public:
    Item(std::string name, T value)
        : name(name), value(value) {}

    std::string get_name() const
    {
        return this->name;
    }
    T get_value() const
    {
        return this->value;
    }
    void print_info() const
    {
        std::cout << "Item name: " << this->name << ", value: " << this->value << std::endl;
    }
};

template <typename T1, typename T2>
struct My_pair
{
    T1 first;
    T2 second;
};

int main()
{
    Item<int> item1{"Item1", 100};
    Item<std::string> item2{"Item2", "Hello"};

    // 类模板嵌套
    Item<Item<std::string>> item3{"Item3", {"Inter", "test"}};
    // auto *Item3_ptr = &item3;
    std::vector<Item<double>> items;
    item1.print_info();
    item2.print_info();

    items.push_back(Item<double>{"Item3", 200.0});
    items.push_back(Item<double>{"Item4", 300.0});

    for (const auto &item : items)
    {
        item.print_info();
    }

    // Item3_ptr->value.print_info(); // 调用嵌套类的成员函数 需要value为public

    std::cout << "===========================" << std::endl;

    My_pair<std::string, int> pair1{"Tom", 100};
    My_pair<int, double> pair2{200, 300.5};

    std::cout << "pair1: " << pair1.first << ", " << pair1.second << std::endl;
    std::cout << "pair2: " << pair2.first << ", " << pair2.second << std::endl;
    return 0;
}