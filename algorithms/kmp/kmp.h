#ifndef __kmp_h__
#define __kmp_h__

#include <iostream>

std::vector<int> build_next(const std::string &pattern);
int kmp_search(const std::string &mian, const std::string &sub, int frompos=0);

#endif
