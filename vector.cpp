#include <iostream>
#include <vector>


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
std::vector<char> vowels(5); // 声明一个大小为5的char类型的vector
std::vector<int> student_scores(10); // 声明一个大小为10的int类型的vector，和array不同，会自动初始化为0

std::vector<char> names{'a', 'b', 'c'}; // 声明一个char类型的vector，初始化为{'a', 'b', 'c'}

std::vector<double> temperature(365,37.5); // 声明一个大小为365的double类型的vector，初始化为37.5


// 获取容器中元素的方法：下标、at()方法（如果越界了，会抛出异常）


// 定义一个二维的vector

int main()
{
    student_scores.at(1) = 90;
    std::cout << student_scores.at(1) << std::endl;

    student_scores.push_back(101);
    std::cout << student_scores.at(10) << std::endl;

    return 0;
}