#include <memory>
#include <mutex>
#include <iostream>
#include <thread>
#include <string>
#include <string>
#include <condition_variable>

using namespace std;

int test_thread()
{
    std::mutex gm;
    auto fun = [](std::string a,std::mutex &mutex){
        std::unique_lock<std::mutex> lk(mutex);
        cout <<"Thread: "<<this_thread::get_id() 
        <<"\t"<<a<<endl;

    };

    thread t(fun,"hello",ref(gm));
    fun("async",gm);

    t.join();
    return 0;
}

int main(int argc, char* argv[]){
    

    return test_thread();
}