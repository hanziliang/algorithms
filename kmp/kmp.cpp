/*
 * =====================================================================================
 *       Filename:  kmp.cpp
 *    Description:  kmp string search algorithm
 *        Version:  1.0
 *        Created:  08/02/2019 16:40:09
 *       Revision:  none
 *       Compiler:  gcc *
 *         Author:  zl03jsj@163.com,
 *   Organization:
 *
 * =====================================================================================
 */

#include "kmp.h"

#include <vector>

using namespace std;


vector<int> build_next(const string &pattern) {

    int size = pattern.size()+1;
    vector<int> next(size);

    int i=1, j=0;

    while( i < size ) {
        if (pattern[i]==pattern[j]) {
            next[++i] = ++j;
        } else {
            if (j>0) { j = next[j];
            } else { next[++i] = 0; }
        }
    }

    return next;
};

int kmp_search(const std::string &mian, const string &sub, int frompos) {
    int miansize = mian.size();
    int subsize = sub.size();

    if (miansize==0 || subsize==0 || miansize<subsize) {
        return -1;
    }

    if (frompos>0) {
        if (frompos > miansize-1) { return -1; }
        string m = mian.substr(frompos, miansize);
        return kmp_search(m, sub);
    }

    vector<int> next = build_next(sub);

    int i=0, ofset=0;
    while(i<subsize && ofset+i < miansize) {
#if 0
        if (sub[i]==mian[ofset+i]) { i++;
        } else {
            i = next[i];
            ofset += i==0?1:i;
        }
#else
        i++ ;
        if (sub[i-1]!=mian[ofset+i-1]) {
            i = next[i-1];
            ofset += i==0?1:i;
        }
#endif
    }

    return i>=subsize?ofset:-1;
}

