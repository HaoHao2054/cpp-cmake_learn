#include <iostream>
#include <thread>
#include <memory>

class A
{
    friend void thread_foo(); // 将thread_foo()声明为友元函数
    private:
        void bar()
        {
            std::cout << "A::bar()" << std::endl;
        }
};

void thread_foo()
{
    std::shared_ptr<A> a = std::make_shared<A>(); // 创建指向class A对象的智能指针
    
    std::thread t(&A::bar, a); // 创建线程，传递成员函数和对象
    t.join(); // 等待线程结束



}

int main()
{
    thread_foo(); // 调用线程函数
    return 0;
}