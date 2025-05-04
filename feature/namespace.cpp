#include <iostream>
#include <stdint.h>


// using namespace std;

using std::cout;
using std::endl;
using std::cin; // 单独导入std中的部分内容


/* 三种变量初始化方法 */
int age = 18; // 直接初始化
int height (180); // 括号初始化，构造函数用法
int weight {70}; // 列表初始化，C++11新特性

/* =与{}初始化变量的区别 */
// short取值范围：-32768~32767
short overflow_num_1 = 32768; // 直接初始化，虽然溢出了，但是不会报错
//short overflow_num_2 {32768}; // 列表初始化，会直接报错



int main()
{
    cout << "Hello, World!" << endl;

    cout << "溢出测试" << endl;
    cout << "直接初始化：short overflow_num_1 = 32768; " << overflow_num_1 << endl;
    // cout << "列表初始化：short overflow_num_2{32768}; " << overflow_num_2 << endl;



    return 0;
}