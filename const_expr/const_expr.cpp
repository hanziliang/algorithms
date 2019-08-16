/*
 * =====================================================================================
 *
 *       Filename:  const_expr.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  12/16/2018 23:22:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>

constexpr int foo(int x)  {return x + 1;}

int main() {
    int a = 1;

    int x = foo(a);

    constexpr int y = foo(a);

    constexpr char* s = "abc";
    constexpr char* str0 = s;

    // change the content of 'const_expr point' pointed..
    str0[1] = 'b';

    // following statment will comiple error:
    // cannot assign to variable 'str0' with const-qualified type 'char *const'
     str0 = s;

    constexpr char* str1 = "abc";

}
