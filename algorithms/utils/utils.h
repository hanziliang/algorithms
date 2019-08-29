//
// Created by 曾亮 on 2019-08-23.
//

#ifndef ALGORITHMS_UTILS_H
#define ALGORITHMS_UTILS_H

#include <vector>
#include <iostream>
#include <climits>
#include <unordered_map>
using namespace std;


//template<class T>
//class MyClass{
//    typedef std::vector<T> storageType; //this is fine
//#if 0
//    typedef storageType::iterator iterator; //the error is here
//#else
//    typedef typename storageType::iterator iterator;
//#endif
//};

template <typename T>
struct UTIL_Type {
    typedef std::vector< std::vector <T> > ARR2D;
};

typedef unordered_map<int, string> INT_ALIAS ;

extern INT_ALIAS ALIAS;

void display_vect(vector<int> &vect, std::unordered_map<int, std::string> *alias=nullptr);
void display_map(std::unordered_map<string, int> &m, unordered_map<int, string> *alias= nullptr);

#define INF SHRT_MAX

#if defined(NAN)
    #undef NAN
#endif

#define NAN int(0)


#endif //ALGORITHMS_UTILS_H
