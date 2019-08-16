/*
 * =====================================================================================
 *
 *       Filename:  user-defined.literals.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/21/2019 14:23:37
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#include <iostream>

typedef long double ull;
ull operator"" _s(ull x) { return x; }
ull operator"" _m(ull x) { return x/60; }
ull operator"" _h(ull x) { return x/3600; }
ull operator"" _d(ull x) { return x/(3600 * 24); }

size_t operator"" _len(char const * str, size_t size) {
    return size;
}

int main(void) {
    float second = 300.0_s;
    float minit = 300.0_m;
    float hour = 300.0_h;
    float day = 300.0_d;

    printf("300(second)=%.4f(s),=%.4f(m),=%.4f(h),=%.4f(d)\n",
            second, minit, hour, day);

    //printf(R"x(length of "abcdef"=)x");

    printf("length of \"abcdef\"=%ld\n", "abcdef"_len );

    return 0;
}
