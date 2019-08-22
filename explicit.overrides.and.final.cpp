/*
 * =====================================================================================
 *
 *       Filename:  explicit.overrides.and.final.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/07/2019 16:59:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

// https://en.wikipedia.org/wiki/C%2B%2B11#Explicit_overrides_and_final

#include <stdlib.h>


// C++11 also adds the ability to prevent inheriting from classes or
// simply preventing overriding methods in derived classes. This is done
// with the special identifier final. For example:
class Base final {
public:
    virtual void some_func(float);
};

class Derived : Base {
    // using Base::some_func;
    void some_func(int); // this will cause warning:'hides overloaded virtual function'

    // The override special identifier means that the compiler will check the base class(es)
    // to see if there is a virtual function with this exact signature. And if there is not,
    // the compiler will indicate an error.
    //          refrence from:
    void some_func(int) override; // this syntax will report previous warning as an error
};
