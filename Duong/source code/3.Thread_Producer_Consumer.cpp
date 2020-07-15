// example for thread::join
#include <iostream>       // std::cout
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include<mutex>
#include<unistd.h>
#include <condition_variable>
#include <semaphore.h>

using namespace std;

std::condition_variable enoughToConsume;
std::condition_variable needToProduce;
mutex   m;
int good = 0;

void produce(){

    while (true) {
        std::unique_lock<std::mutex> l(m);
        cout<<"[produce] start to Produce"<<endl;
        while (good < 10) {
            good++;
            sleep(1);
            cout<<"[produce] produced: " << good <<endl;
        }
        cout<<"[produce] ready to Consume"<<endl;
        enoughToConsume.notify_one();
        needToProduce.wait(l);
    }
}

void consume(){
    while (true) {
        std::unique_lock<std::mutex> l(m);
        cout << good << endl;
        if(good <10){
            cout<<"[consume] wait to produce"<<endl;
            enoughToConsume.wait(l);
        }
        cout<<"[consume] start to Consume"<<endl;
        while (good > 0) {
            good --;
            usleep(500000);
            cout<<"[consume] consume remain: " << good <<endl;
        }
        needToProduce.notify_one();
    }
}
int main(){
    std::thread t1 (produce);
    sleep(2);
    std::thread t2 (consume);
    t1.join();
    t2.join();
    return  0;
}
