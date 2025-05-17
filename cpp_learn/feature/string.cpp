#include <iostream>
#include <string>
#include <vector>
#include <cstring>



// c风格字符串，本质上是一个字符数组
char my_name [20] {"hello"};
// 不可以用=来赋值
// my_name = "world";

/* 
c++风格字符串
本质上是STL中的一个string类的对象，内存中连续，动态大小。可与c风格字符串互相转换
std::string my_name2 {"hello"};
*/

std::string s1;  // 声明一个空字符串
std::string s2 {"course"}; // 声明一个字符串并赋值
std::string s3 {s2}; // 拷贝s2
std::string s4 {s2, 0, 3}; // 拷贝s2的前3个字符
std::string s5 (10, 'X'); // 声明一个字符串，长度为10，每个字符都是'X'


int main()
{
    std::strcpy(my_name, "hello ");    // 字符串赋值
    std::strcat(my_name, "world !");   // 字符串拼接
    std::cout << my_name << std::endl;

    // 赋值
    s1 = "c++ is great";
    s2 = s1;

    // 拼接
    s3 = s1 + " " + s2;
    // 注意，拼接操作不能用于两个c风格字符串 如：s3 = “sss” + “hell0”;


    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;

    // 获取string的具体某个字符
    
    for (auto c: s3)
    {
        std::cout << c;
    }
    std::cout << std::endl; // 通过遍历的方式，打印string的每个字符

    for (int c: s3)
    {
        std::cout << c;
    }
    std::cout << std::endl; // 通过遍历的方式，打印string的每个字符的ASCII码值

    // 获取string的长度
    std::cout << s3.length() << std::endl;

    return 0;
}