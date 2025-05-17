#ifndef HOUSE_HPP
#define HOUSE_HPP

#include <iostream>
#include <string>
#include <vector>

class House
{
public:
    // 构造函数
    House(int area);

    void Where() const; // 房屋地址

    // 析构函数
    ~House();

    // 重写拷贝构造函数，使之成为深拷贝
    House(const House &house);

private:
    int Area;  // 房屋面积
    int *pKey; // 房屋钥匙，指向房屋的地址
};

#endif 
