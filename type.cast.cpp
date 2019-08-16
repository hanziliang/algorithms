/*
 * =====================================================================================
 *
 *       Filename:  type.cast.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/18/2019 16:06:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Baseuthor:  YOUR NBaseME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <thread>
using namespace std;
class Base {
public:
    int _x;
    Base(int x): _x(x) {};
    virtual void Show() {
        cout << "value of x=" << this->_x << endl;
    }
    void ShowA() {
        cout << "value of x=" << this->_x << endl;
    }

};

class Derived:public Base {
public:
    Derived(int x, int y) : Base(x), _y(y) {
    }

    int _y;
    void ShowA() {
        cout << "x=" << _x << ",y=" << _y << endl;
    }

};

int main() {
    Base *a = new Base(8);
    // no error
    int *b = (int *)a;
    // no error
    void *d = static_cast<Base*>(a);

#if 0
    // this will cause compile error, because of type checking
    int *c = static_cast<Base*>(a);
#endif


    Derived *e = new Derived(3, 5);
    // to use dynamic_cast, Base must be 'polymorphic',
    // witch means, it Base must have a 'virtual' function..
    Derived *f = dynamic_cast<Derived*>(a);
    if (f==nullptr) {
        // should pirnt 'f is null'
        cout << "f is null" << endl;
    } else {
        cout << " f is not null" << endl;
    }

    Base *g = dynamic_cast<Base*>(e);
    if (g==nullptr) {
        cout << "g is null" << endl;
    } else {
        // should pirnt 'g is not null'
        cout << "g is not null" << endl;
    }

    try {
        // bad_cast will be catched..
        Derived &h = dynamic_cast<Derived&>(*a);
        cout << "dynamic_cast success" << endl;
    }
    catch (std::bad_cast err){
        cout << "bad_cast from '*a' to 'Derived&', detail : "<< err.what() << endl;
    }

    try {
        Base &i =dynamic_cast<Base&>(*e);
        cout << "dynamic_cast success" << endl;
    }
    catch (std::bad_cast err){
        cout << "bad_cast from '*a' to 'Base&', detail : " << err.what() << endl;
    }

    std::this_thread::sleep_for(std::chrono::seconds(2));
}
