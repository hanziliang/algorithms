/*
 * =====================================================================================
 *
 *       Filename:  std.thread.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/26/2019 13:37:54
 *       Revfision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <thread>
#include "iostream"
#include <functional>
#include <chrono>
#include <vector>
#include <mutex>

class TestThread {
public:
    std::mutex *_mutx;
    int volatile x;
    TestThread(int _x):x(_x){
        _mutx = new std::mutex();
        printf("constructor is called\n");
    };

    ~TestThread() {
        printf("destroy...\n");
        if (_mutx!=nullptr) {
            delete _mutx; _mutx = nullptr;
        }
    }

    void async_display() {
        std::function<void(void)> do_display = [this](void) {
            _mutx->lock();
            printf("value of this->x = %d\n", x);
            x = x+1;
            _mutx->unlock();
        };

        std::thread t(do_display);
        t.detach();
        // t.join();
    }
    void display(int i=0) {
        printf("value of x = %d\n", x);
        if (i==0) return;
        printf("value of i = %d\n", i);
    }
};

class X {
public:
    char * _x = NULL;

    X() = delete;

    X(const X& x) {
        printf("x.copy constructor\n");
        if (x._x==NULL) { return; }
        size_t size = strlen(x._x);
        _x = new char[size + 1];
        memcpy(_x, x._x, size);
    }

    X(const char *x) {
        printf("constructor is call...\n");
        if (x==NULL) { return; }

        size_t size = strlen(x);
        _x = new char[size + 1];
        memcpy(_x, x, size);
    }

    X(X &&x):_x(x._x) {
        x._x = nullptr;
        printf("move copy constructor is call\n");
    }

    ~X() {
        printf("destory x\n");
        if (_x!=NULL) {
            printf("call delete[] _x;\n");
            delete[] _x;
            _x = NULL;
        }
    };

    void display() { printf("value of x:%s\n", _x); };
};

int main ( int argc, char *argv[] )
{
    X x("hello world");
    x.display();
    std::function<void(void)> xf = std::bind(&X::display, x);

    return 0;
    xf();

    std::this_thread::sleep_for(std::chrono::seconds(2));





    std::mutex *tmp_mutx = new std::mutex();
    delete tmp_mutx;

    TestThread th_inst = {0};

    th_inst.display();
    std::vector<int> vec = {1,2,3,4,5};
//    for ( int x : vec ) { th_inst.async_display(); }

    for ( int x=0; x<1; x++) { th_inst.async_display(); }

    printf("all displayed...........\n");
    std::this_thread::sleep_for(std::chrono::seconds(2));

    printf("....................\n");

    std::function<void(int)> f = std::bind(&TestThread::display, th_inst, std::placeholders::_1);
    // std::function<void(int)> f_ref = std::bind(&TestThread::display, std::ref(th_inst), std::placeholders::_1);

#if 0
    std::thread thread_class(f, 10000);
    thread_class.detach();

    std::thread thread_class_(&TestThread::display, th_inst, 3);

    thread_class_.detach();

    std::function<void(void)> f_void = std::bind(&TestThread::display, th_inst, 5);
    std::thread thread_class_0(f_void);
    thread_class_0.detach();
    printf("....................\n");

    th_inst.display();

    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::this_thread::sleep_for(std::chrono::seconds(2));
#endif
    return EXIT_SUCCESS;
}
