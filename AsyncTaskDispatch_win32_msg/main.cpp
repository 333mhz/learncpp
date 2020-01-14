
#include <memory>
#include <mutex>
#include <iostream>
#include <thread>
#include <string>
#include <string>
#include <condition_variable>

#include "asynchronous_task_dispatch.h"

using namespace std;

class Singleton {
public:
    //static Singleton& GetInstance()
    //{
    //    if (!instance_) {
    //        lock_guard<mutex> lk(mutex_);
    //        if (!instance_) {
    //            instance_.reset(new Singleton);//the problem is here.
    //        }
    //    }
    //    return *instance_;
    //}//DCLP
    static Singleton& GetInstance() {
        static once_flag s_flag;
        call_once(s_flag, [&]() {
            instance_.reset(new Singleton);
            });
    }
    ~Singleton() = default;

private:
    static unique_ptr<Singleton> instance_;

    static mutex mutex_;

    Singleton() = default;

    Singleton(const Singleton&) = delete;

    Singleton& operator=(const Singleton&) = delete;
};

int test_thread()
{
    std::mutex gm;
    auto fun = [](std::string a, std::mutex& mutex) {
        std::unique_lock<std::mutex> lk(mutex);
        cout << "Thread: " << this_thread::get_id()
            << "\t" << a << endl;

    };

    thread t(fun, "hello", ref(gm));
   
    fun("async", gm);
    t.join();
   
    return 0;
}


class test_atd :public std::enable_shared_from_this<test_atd>
{
public:
    test_atd(){
        //AsyncTaskDispatch::init_main_thread_dispatcher();
    }
    ~test_atd() {
    }
    // AsyncTaskDispatch::main_thread()->post_task(make_closure(&test_async), true);
    void test_async()
    {

        auto a = []() {
            cout << "hello" << endl;
        };
        AsyncTaskDispatch::current()->post_task(make_closure(a), true);
        //a();
        cout << "world" << endl;
    }
};
int main(int argc, char* argv[]) {
  /* AsyncTaskDispatch::init_main_thread_dispatcher();
    test_atd * a = new test_atd();
    AsyncTaskDispatch::main_thread()->post_task(make_closure(&test_thread), true);*/
    //AsyncTaskDispatch::main_thread()->post_task(make_closure(&test_atd::test_async), true);
    //a->test_async();
        //a->test_async();
     //AsyncTaskDispatch::main_thread()->process_nestable_task();
     //AsyncTaskDispatch::current()->process_nestable_task();
   
    //test_async();
  /*  std::thread tt;
    {
    std::thread t([](){
        cout << "test";
        });
    
    tt = std::move(t);
    }*/
    echo(int)((0.1 + 0.8) * 10);
    return 0;

}