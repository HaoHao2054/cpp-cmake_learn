#include <iostream>
#include <vector>
#include <string>

// 函数重载
// int add_numbers(int a, int b);
// double add_numbers(double a, double b);


/*
函数传参：引用传递

默认情况下，形参只是实参的一个拷贝，函数内部对形参的修改不会影响到实参

如果想要在函数内部改变实参的值，使用引用传参给函数，形参会变成实参的一个别名
*/

void double_number(int &num)
{
    num *= 2;
}

/*
除了解决了函数内部无法修改实参的值的问题，引用传参还有一个好处：
引用传参可以避免拷贝大型对象的开销，提高程序的性能
*/

// 通过引用传参打印一个vector
void print_vector(const std::vector<std::string> &vec) // 通过const来修饰，方式函数内部对vec的修改
{
    for (auto i: vec)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}


int main()
{
    int test_num = 10;
    std::cout << "test_num: " << test_num << std::endl;
    double_number(test_num);
    std::cout << "test_num: " << test_num << std::endl;

    std::vector<std::string> test_vec {"hello", "world", "!"};
    print_vector(test_vec);

    return 0;
}