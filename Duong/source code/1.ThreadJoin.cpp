// example for thread::join
#include <iostream>       // std::cout
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include <unistd.h>
using namespace std;
void Foo(){
          std::cout << "xin chao" << endl ;
         }

void pause_thread()
{
    Foo();
  for(int i = 0 ; i < 10 ; i ++){
     std::cout << "Number " << i << "\n";
     usleep(50000000);
  }
}
void pause_thread2()
{
  for(int i = 20 ; i < 30 ; i ++){
     std::cout << "Number " << i << "\n";
     usleep(50000000);
  }
}
void pause_thread3()
{
  for(int i = 40 ; i < 50 ; i ++){
     std::cout << "Number " << i << "\n";
     usleep(5000000);
  }
}


int main()
{
    Foo();
  std::cout << "Creating 3 threads...\n";
  std::thread t1 (pause_thread);
  std::cout << "thread1 joined\n";
  t1.join();

  std::thread t2 (pause_thread2);
  std::cout << "thread2 joined\n";
  t2.join();

  std::thread t3 (pause_thread3);
  std::cout << "thread3 joined\n";
  t3.join();

  sleep(1200);
  std::cout << "Finished!\n";
  return 0;
}
