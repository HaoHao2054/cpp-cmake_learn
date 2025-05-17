#include <iostream>
#include <thread>
#include <mutex>


/* 创建一个互斥量 */
std::timed_mutex mtx;

int a = 0;

void func()
{
    for (int i = 0; i < 2; i++)
    {
        std::unique_lock<std::timed_mutex> lock(mtx, std::defer_lock); // 锁定互斥量
        if (lock.try_lock_for(std::chrono::seconds(1))) // 尝试锁定互斥量，最多等待1秒
        {
            
            std::this_thread::sleep_for(std::chrono::seconds(2)); // 模拟耗时操作
            a += 1;
            std::cout << "Thread " << std::this_thread::get_id() << " incremented a to " << a << std::endl;
        }
    }
}

int main()
{
    std::thread t1(func);
    std::thread t2(func);

    t1.join(); // 等待线程结束
    t2.join(); // 等待线程结束


    std::cout << "Final value of a: " << a << std::endl; // 输出最终的a值
    return 0;
}