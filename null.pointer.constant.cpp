/*
 * =====================================================================================
 *
 *       Filename:  null.pointer.constant.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/08/2019 14:42:19
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

using namespace std;

//Null pointer constant

//For the purposes of this section and this section alone, every occurrence of “0” is meant as “a constant expression which evaluates to 0, which is of type int”. In reality, the constant expression can be of any integral type.

//Since the dawn of C in 1972, the constant 0 has had the double role of constant integer and null pointer constant. The ambiguity inherent in the double meaning of 0 was dealt with in C by using the preprocessor macro NULL, which commonly expands to either ((void*)0) or 0. C++ forbids implicit conversion from void * to other pointer types, thus removing the benefit of casting 0 to void *. As a consequence, only 0 is allowed as a null pointer constant. This interacts poorly with function overloading:

// c++进制了从 void* 到其它指针类型的隐式转换, 因此丢失
// #define NULL ((void*)0),的好处,
// 所以在c++中, NULL的定义为: #define NULL 0
// 在调用:foo(NULL)的时候, 出现 无法找到匹配函数的错误(本应匹配到foo(char*))
// 就是在c++中, void* 无法隐式转换为其它类型指针的原因.

void foo(char *) { std::cout<< "foo(char*) is call" << std::endl; }
void foo(int) { std::cout<< "foo(int) is call" << std::endl; }

//#undef NULL
// with standard std=c, 'NULL' is defined as ((void*)0),
// with standard std=c++, 'NULL' is defined as 0, it may be varis by operation systems
#undef NULL
#ifdef __cplusplus
#  if !defined(__MINGW32__) && !defined(_MSC_VER)
#    define NULL __null
#  else
#    define NULL 0
#  endif
#else
#  define NULL ((void*)0)
#endif

int main() {
    // cause error : no matching function for call to 'foo'
    foo(NULL);
    foo(nullptr);
    /*
       Note that foo(nullptr_t) will actually call foo(char *) in the example above using an implicit conversion,
       only if no other functions are overloading with compatible pointer types in scope.
       If multiple overloadings exist, the resolution will fail as it is ambiguous,
       unless there is an explicit declaration of foo(nullptr_t).

       In standard types headers for C++11, the nullptr_t  type should be declared as:
       typedef decltype(nullptr) nullptr_t;
       but not as:
       typedef int nullptr_t; // prior versions of C++ which need NULL to be defined as 0
       typedef void *nullptr_t; // ANSI C which defines NULL as ((void*)0)
       */
}
