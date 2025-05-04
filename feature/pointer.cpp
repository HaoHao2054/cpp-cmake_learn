#include <iostream>
#include <string>
#include <vector>

// 初始化指针

int *int_ptr{nullptr};
double *double_ptr{nullptr};
std::string *string_ptr{nullptr};

std::vector<std::string> my_str_vec{"one", "two", "three"};
std::vector<std::string> *vec_ptr{&my_str_vec};


// 函数通过指针传参
void double_data(int *int_ptr)
{
    *int_ptr *= 2; // 通过解引用的方式，将指针指向的变量的值乘以2
}

void display(std::vector<std::string> *v)
{
    // 修改vector中的第一个元素
    (*v).at(0) = "ONE"; // 解引用
    v->at(1) = "TWO"; // 解引用
    v->at(2) = "THREE"; // 解引用
    for (auto s:*v)
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;

}

// 函数返回指针

// 返回动态分配的内存
int *create_array(size_t size, int init_value = 0) // 初始值默认为0
{
    int *new_storage {nullptr};

    new_storage = new int[size]; // 分配一个int类型的数组，指针指向数组的第一个元素

    // 初始化数组
    for (size_t i{0}; i < size; ++i)
    {
        *(new_storage + i) = init_value; // 解引用
    }
    return new_storage; // 返回指针
}

int main()
{
    int num{100};
    int_ptr = &num;
    std::cout << "num: " << num << std::endl;
    std::cout << "int_ptr: " << int_ptr << std::endl;
    std::cout << "int_ptr: " << *int_ptr << std::endl; // 解引用

    std::cout << "\n-------------------------" << std::endl;
    std::cout << "vec_ptr: " << vec_ptr << std::endl;
    std::cout << "vec_ptr: " << vec_ptr->size() << std::endl; // 解引用
    std::cout << "vec_ptr: " << vec_ptr->at(0) << std::endl;  // 解引用

    for (auto s : *vec_ptr)
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    // 动态内存分配
    // 使用new关键字
    int *int_ptr2{nullptr};

    int_ptr2 = new int {100}; // 分配一个int类型的内存，赋值为100
    std::cout << "int_ptr2: " << int_ptr2 << std::endl;
    std::cout << "int_ptr2: " << *int_ptr2 << std::endl;

    *int_ptr2 = 200; // 赋值为200
    std::cout << "int_ptr2: " << *int_ptr2 << std::endl;
    delete int_ptr2; // 释放内存

    // 动态分配数组
    int *int_ptr_arr{nullptr};

    int_ptr_arr = new int[5] {10, 20, 30, 40, 50}; // 分配一个int类型的数组，指针指向数组的第一个元素
    std::cout << "int_ptr_arr: " << int_ptr_arr << std::endl;
    std::cout << "int_ptr_arr: " << int_ptr_arr[0] << std::endl;

    delete int_ptr_arr; 

    // 函数通过指针传参
    int num2 {100};
    double_data(&num2); // 需要传入变量的地址  
    std::cout << "num2: " << num2 << std::endl;

    std::vector<std::string> stooges {"Larry", "Moe", "Curly", "Shemp", "Joe"};
    display(&stooges); // 需要传入变量的地址

    return 0;
}