#include "../dynamic/match-sum/match_sum.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if(argc==1) {
        printf("need a 'sum' argument\n");
        return 0;
    }

    int sum = atoi(argv[1]);

    std::vector<int> arr { 3, 5, 7, 2, 11};

    time_t start, end;

    std::vector< std::vector<const bool*> > cache(arr.size(), std::vector<const bool*>(sum+1, nullptr));

    int total = 0;
    std::cout<<"array is:[";
    std::for_each(arr.cbegin(), arr.cend(),  [&total](int x) {
            total+=x;
            std::cout<< x << "," ; });

    std::cout<<"] totalvalue="<<total<<std::endl<<"to find value:"<<sum<<std::endl;

    bool isfind = false;

#if 0
    start = time(0);
    isfind = subset_recursion(arr, arr.size()-1, sum);
    end = time(0);

    printf("find_recursion result=%s, timecast=%.f(second)\n",
            isfind?"true":"false", difftime(end, start));

    start = time(0);
    isfind = subset_memoize(arr, cache, arr.size()-1, sum);
    end = time(0);

    printf("find_memoize result=%s, timecast=%.f(second)\n",
            isfind?"true":"false", difftime(end, start));

#endif

    start = time(0);
    isfind = subset_dynamic(arr, sum);
    end = time(0);

    printf("find_dynamic result=%s, timecast=%.f(second)\n",
           isfind?"true":"false", difftime(end, start));


}
