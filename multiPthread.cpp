#include<iostream>
#include<thread>
#include<string>
using namespace std;
void threadfun1()
{
   cout << "threadfun1\r\n" << endl;
   this_thread::sleep_for(chrono::seconds(1));
   cout << "threadfun1 finish\r\n" << endl;
}
void threadfun2(const int num, const string str, int& result)
{
    cout << "threadfun2\r\n num:" << num << "str:"<< str << "\r\n" << endl;
    this_thread::sleep_for(chrono::seconds(5));
    result = 5;
    cout << "threadfun2 finish result:" << result << endl;
}
int main()
{
   thread threadFirst(threadfun1);
   cout <<"firstTheadId:" << threadFirst.get_id() << endl;
   cout << "firstThread joinable" <<threadFirst.joinable() <<endl;
   const int inputValue = 10;
   const string inputStr = "multiThread";
   int result = 3;
   thread threadSecond(threadfun2, inputValue, inputStr, ref(result));
   cout <<"secondThreadId:" <<  threadFirst.get_id() << endl;
   cout << "secondThreadId joinable:" << threadFirst.joinable() << endl;
   cout << "first thread join result:" << result << endl;
  // threadFirst.join();
   threadFirst.detach();
   threadSecond.join();
    cout << "second thread join" << result << endl;

  // threadSecond.detach();
  thread threadThree;
    return 0;
}
