// example for thread::join
#include <iostream>       // std::cout
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <vector>
#include<mutex>
#include<unistd.h>
#include <queue>

using namespace std;
queue<int> q;
std::mutex _m;
std::recursive_mutex _rm;
void insertList(){
    cout<<"[insertList] enter function" << endl;
    //std::lock_guard<std::mutex> l(_m);
    //_m.lock();
    _m.try_lock();
    cout<<"[insertList] mutex locked"<<endl;
    for(int i = 0 ; i < 15 ; i++){
        q.push(i);
        cout<< "[insertList] Queue size: " << q.size() << endl;
        sleep(1);
    }
    _m.unlock();
    cout<<"[insertList] mutex unlocked, exit function"<<endl;
}
void deleteList(){
    cout<< "[deleteList] enter function" << endl;
    _m.lock();
    while (!q.empty()) {
        q.pop();
        cout<< "[deleteList] Queue size: " << q.size() << endl;
        sleep(1);
    }
    _m.unlock();
    cout<< "[deleteList] mutex unlocked, exit function" << endl;
}

int mainewqe()
{
  std::thread t1 (insertList);
  sleep(2);
  std::thread t2 (deleteList);
  t1.join();
  t2.join();

  std::cout << "Finished!\n";
  return 0;
}
