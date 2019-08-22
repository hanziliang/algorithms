/*
 * =====================================================================================
 *
 *       Filename:  Unrestricted.unions.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/15/2019 11:21:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <new> // Needed for placement 'new'.
#include <thread>
#include <chrono>

struct Point
{
    Point():Point(5,5) {
        std::cout<<"Point::Point() is called"<<std::endl;
    }

    Point(int x, int y): x_(x), y_(y) {
        std::cout<<"Point::Point("<<x<<","<<y<<") is called"<<std::endl;
    }

    Point(const Point &p) {
        x_ = p.x_;
        y_ = p.y_;
        std::cout << "Point(const point&p) is called" << std::endl;
    }

    Point(Point&& p) {
        x_ = p.x_;
        y_ = p.y_;
        std::cout << "Point(const point&&p) is called" << std::endl;
    }

    int x_, y_;

    void Show() {
        std::cout << "this=" << uint64_t(this) << ",x=" << x_ << ",y=" << y_ << std::endl;
    }
};

union U
{
    int z;
    double w;
    Point p; // Invalid in C++03; valid in C++11.
    U() {} // Due to the Point member, a constructor definition is now needed.
    U(const Point& pt) : p(pt) {
        std::cout << "U(const Point&) is called" << std::endl;
    } // Construct Point object using initializer list.

    U& operator=(const Point& pt) {
        std::cout << "U& operator=(const Point&)is called"<<std::endl;
        new(&p) Point(pt);
        return *this;
    } // Assign Point object using placement 'new'.
};

int main(void) {
    Point p(10, 11);
    p.Show();

    std::cout<<"--------------------"<<std::endl;
    U u = {p};
    u.p.Show();
    std::cout<<"--------------------"<<std::endl;
    u = p;
    u.p.Show();

    std::cout<<"--------------------"<<std::endl;
    // placement 'new'
    // 'pp' and '&p' point to the same address,
    // the constructor is called, and reset _x, _y to 5, 5
    Point *pp = new(&p) Point();
    pp->Show();

    std::this_thread::sleep_for(std::chrono::seconds(2));

    // the above code, do the same things as follow:
    // since only compiler can invoke the constructor of a  class directly,
    // there is an error for : pc->Point::Point();
    // but compiler have no..
#if 0
    Point *pc;
    try {
        void* mem = ::operator new(sizeof(Point), &p); //借用内存
        pc = static_cast<Point*>(mem);//安全转换
        pc->Point::Point(5,5); //
    }
    catch (std::bad_alloc){
        //若失败 不执行构造函数
    }
#endif
}
