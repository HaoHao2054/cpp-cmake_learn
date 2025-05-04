#include "house.hpp"
#include <iostream>

// 构造函数
House::House(int area)
    : Area(area), pKey(nullptr)
{
    pKey = new int(area); // 创建对象时，由构造函数申请一块内存作为访问的地址，钥匙指针指向它
}

House::~House()
{
    delete pKey;    // 释放内存
    pKey = nullptr; // 避免悬空指针
}

void House::Where() const
{
    std::cout << "房屋地址：" << this->pKey << std::endl;
    std::cout << "房屋面积：" << this->Area << std::endl;
}

House::House(const House &house)
    : Area(house.Area), pKey(nullptr)
{
    pKey = new int(house.Area); // 深拷贝
    std::cout << "拷贝构造函数被调用，重新申请一块内存作为房屋的地址" << std::endl;
}