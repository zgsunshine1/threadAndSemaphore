#include <iostream>
#include <mutex>
#include <thread>
std::mutex g_mutex1;

std::mutex g_mutex2;
// void thread1()
// {
//     while(1)
//     { 
//     g_mutex1.lock();
//     g_mutex2.lock();
//     std::cout << "thread1 do work ..." << std::endl;
//     g_mutex2.unlock();
//     g_mutex1.unlock();
//     }
// }

void thread1()
{
    while(1)
    {
    g_mutex2.lock();     
    g_mutex1.lock();
    std::cout << "thread1 do work ..." << std::endl;
    g_mutex2.unlock();
    g_mutex1.unlock();
    }
}
void thread2()
{
    while(1)
    {
        g_mutex2.lock();
        g_mutex1.lock();
        std::cout << "thread2 do work ..." << std::endl;
        g_mutex1.unlock();
        g_mutex2.unlock();
    }
}
int main()
{
    std::thread t1(thread1);
    std::thread t2(thread2);
    t1.join();
    t2.join();
    return 0;
}