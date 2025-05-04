#include <iostream>
#include <thread>
#include <string>

void printHelloWorld()
{
    while(1)
    {
        std::cout << "Hello, World!" << std::endl;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void printmsg(std::string msg)
{
    std::cout << msg << std::endl;
}

int main()
{

    /* 创建一个线程 */
    /* main函数是主线程 */
    std::thread thread1(printHelloWorld);
    std::thread thread2(printmsg, "Hello, Thread!"); // 给线程传递参数

    /* join()方法，检查对应的线程有没有结束，如果结束了，才会继续向下执行 */

    bool isJoin = thread1.joinable(); // 检查线程1是否可以连接，会返回一个bool值
    if (isJoin)
    {
        thread1.join(); // 等待线程1结束
        /*
        如果线程不可以连接，join()方法会抛出一个异常（std::system_error）
        */
    }

    thread2.join(); // 等待线程2结束
    // thread1.detach(); // 分离线程1，允许它在后台运行，一般不用这个

    /* join方法是阻塞的，只有对应的线程执行完，程序才会继续往下走 */

    std::cout << "Thread 2 has finished execution." << std::endl;
    return 0;
}