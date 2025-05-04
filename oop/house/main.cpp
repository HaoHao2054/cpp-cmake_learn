#include <iostream>
#include <string>

#include "house.hpp"


int main()
{
    // 创建房屋对象
    House house1(100);
    house1.Where(); // 调用成员函数

    // 通过拷贝的方式创建房屋对象
    House house2(house1);
    house2.Where(); // 调用成员函数

    return 0;
}