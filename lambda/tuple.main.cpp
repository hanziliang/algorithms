/*
 * =====================================================================================
 *
 *       Filename:  implement.bind.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/27/2019 11:11:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include "tuple.template.h"

int main() {
    ___tuple<int, const char*, float> _tuple(1, "hello world", 1.9);
    print_line();

    std::cout <<
        __get_tuple_at<0>(_tuple) << "\n" <<
        __get_tuple_at<1>(_tuple) << "\n" <<
        __get_tuple_at<2>(_tuple) << "\n" << std::endl;

    return 0;
}

