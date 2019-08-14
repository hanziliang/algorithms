#include "../kmp/kmp.h"

using namespace std;

int main() {
    string mian = "abcdeabaaaabcabcderf", sub = "bcd";

    int ofset=0, findpos=0;

    printf("main string : %s\n", mian.c_str());

    while(findpos!=-1) {
        findpos = kmp_search(mian, sub, ofset);

        ofset = ofset + findpos;

        if (findpos>=0) {
            printf("find pos    : %s%s\n", string(ofset, ' ').c_str(), sub.c_str());
        }

        ofset++;
    }

    return 0;
}


