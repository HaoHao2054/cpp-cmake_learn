#include <cstddef>
#include <iostream>
#include <vector>
#include <iomanip>

/*
容器：vector
标准模板库STL中提供的一个动态数组类

动态大小、和数组类似的语法用法、高性能、越界检查、有用的函数（vector类的各种方法）

性质：
所有元素都是同一类型

常用方法
.at() 根据下标索引对应的元素
.push_back() 添加到vector的末尾
*/

// 声明
// std::vector<int> vowels; // 声明一个空的int类型的vector
std::vector<char> vowels(5);         // 声明一个大小为5的char类型的vector
std::vector<int> student_scores(10); // 声明一个大小为10的int类型的vector，和array不同，会自动初始化为0

std::vector<char> names{'a', 'b', 'c'}; // 声明一个char类型的vector，初始化为{'a', 'b', 'c'}

std::vector<double> temperature(365, 37.5); // 声明一个大小为365的double类型的vector，初始化为37.5

// 获取容器中元素的方法：下标、at()方法（如果越界了，会抛出异常）

// 定义一个二维的vector
std::vector<std::vector<int>> movie_ratings{
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}};

int main()
{
    student_scores.at(1) = 90;
    std::cout << student_scores.at(1) << std::endl;

    student_scores.push_back(101);
    std::cout << student_scores.at(10) << std::endl;

    // 打印二维vector的成员变量
    std::cout << movie_ratings.at(0).at(0) << std::endl;

    // for 循环遍历vector
    std::vector<int> nums{1, 2, 3, 4, 5};
    for (size_t i = 0; i < nums.size(); i++)
    {
        std::cout << nums.at(i) << std::endl;
    }

    // 基于范围的循环 c++11新特性
    std::vector<double> temps {23.1, 23.2, 23.3, 23.4, 23.5, 23.6, 23.7, 23.8, 23.9, 24.0};
    double average_temp {};
    double sum_temp {};
    for (auto temp: temps) // 直接使用auto来自动推断类型
    {
        sum_temp += temp;
    }

    average_temp = sum_temp / temps.size();
    // 设置精度，保留一位小数
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Average temperature: " << average_temp << std::endl;

    // 或者直接传入序列
    // for (auto temps: {23.1, 23.2, 23.3, 23.4, 23.5})
    // {
    //     sum_temp += temps;
    // }

    // 打印字符串
    for (auto c: {"hello, world", "hello, c++"})
    {
        std::cout << c << std::endl;
    }

    return 0;
}