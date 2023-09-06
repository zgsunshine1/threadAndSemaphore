#include "semaphore.h"
#include <thread>
#include <iostream>
using namespace std;
 
Semaphore sem(0);
 
void funA()
{
    sem.wait();
    //do something
    cout << "funA" << endl;
}
 
void funB()
{
    this_thread::sleep_for(chrono::seconds(1));
    //do something
    cout << "funB" << endl;
    sem.signal();
}
 
int main()
{
    thread t1(funA);
    thread t2(funB);
    t1.join();
    t2.join();
}