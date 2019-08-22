/*
 * =====================================================================================
 *
 *       Filename:  volatile.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/22/2019 14:25:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <iostream>
using namespace std;

int main(int argc,char* argv[])
{
    int i=10;
    int a=i;
    unsigned long ptr_number_1 = (unsigned long)&i;
    unsigned long ptr_number_2 = 0;
    cout<<a<<endl;

    __asm__ __volatile__(
        "movl -4(%ebp),80 \n" \
        "movl -16(%ebp),-4(%ebp-4) \n" \
    );

    int b=i;
    cout<<b<<endl;
    cout << "number1" << ptr_number_1 << endl;
    cout << "number2" << ptr_number_2 << endl;
}
