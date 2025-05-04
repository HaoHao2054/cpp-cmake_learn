#include <iostream>
#include <memory>


/* 
智能指针：
只能指向heap中的内存
智能指针是一个类模板，提供了对动态分配内存的管理功能，对原始指针做了一层封装

三种常见的智能指针：
1. std::unique_ptr：独占式智能指针，不能被复制，只能被移动，不能共享所有权
2. std::shared_ptr：共享式智能指针，可以被多个指针共享，引用计数
3. std::weak_ptr：弱引用智能指针，不能拥有对象的所有权，不能直接访问对象，必须通过std::shared_ptr来访问 
*/