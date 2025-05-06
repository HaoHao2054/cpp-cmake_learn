#include <iostream>
#include <memory>
#include <string>
#include <vector>

/*
模板template:
是一种蓝图，包括函数模板和类模板，可以动态替换任何数据类型
    函数模板：可以用来创建一个函数的多个版本，函数参数类型可以是任意类型
    类模板：可以用来创建一个类的多个版本，类成员变量和成员函数的类型可以是任意类型
*/
namespace my
{
    template <typename T>
    T max(T a, T b)
    {
        return (a > b) ? a : b; // 传入的类型，必须支持 > 这个操作符
                                // 如果变量类型不支持这个运算符，比如自定义的类，那么可以在类中重载这个运算符，以支持
    }

    template <typename T1, typename T2>
    void print(T1 a, T2 b)
    {
        std::cout << "a: " << a << ", b: " << b << std::endl;
    }
} 

int main()
{
    int a{10}, b{20};
    double x{10.5}, y{20.5};
    std::string str1{"Hello"}, str2{"World"};

    std::cout << "Max of " << a << " and " << b << " is: " << my::max<int>(a, b)
              << std::endl; // 显式调用模板函数，也可以不指定，由编译器推导
    std::cout << "Max of " << x << " and " << y
              << " is: " << my::max<double>(x, y) << std::endl;
    std::cout << "Max of " << str1 << " and " << str2
              << " is: " << my::max<std::string>(str1, str2) << std::endl;

    // 使用模板函数打印不同类型的参数
    my::print(a, str1);                   // 隐式指定参数，让编译器推导
    my::print<int, std::string>(a, str1); // 显式指定参数

    return 0;
}