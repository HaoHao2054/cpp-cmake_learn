#include <iostream>
#include <thread>
#include <mutex>
#include <string>

class Log
{
    public:
        /* 构造函数 */
        Log()
        {
            std::cout << "Log constructor" << std::endl;
        }

        /* 拷贝构造 */
        Log(const Log& log) = delete;
        Log& operator = (const Log& log) = delete; // 禁止拷贝构造和赋值

        /* 使用静态方法来获取Log的引用 */
        static Log& GetInstance()
        {
            // static Log log; // 懒汉模式
            // return log;

            // 饿汉模式
            static Log *log = nullptr;

            if (!log) log = new Log;

            return *log;
        }

        /* 打印日志的方法 */
        void PrintLog(std::string msg)
        {
            std::cout << __TIME__ << ' ' << msg << std::endl;
        }
};

void func()
{
    Log::GetInstance().PrintLog("error");
}

int main()
{
    std::thread t1(func);
    std::thread t2(func);
    
    t1.join(); // 等待线程结束
    t2.join(); // 等待线程结束

    return 0;
}