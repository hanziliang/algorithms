#include "./match_sum.h"
#include <iostream>
#include <time.h>


const bool EXIST=true, NoEXIST=false;

bool subset_recursion(std::vector<int> &arr, int index, int sum) {

    if (index<=0) {
        return arr[index]==sum;
    } else {
        if ( arr[index] > sum ) {
            return subset_recursion(arr, index-1, sum);
        } else if ( arr[index] == sum ) {
            return true;
        } else {
            return subset_recursion(arr, index-1, sum-arr[index]) ||
                subset_recursion(arr, index-1, sum);
        }
    }
}

bool subset_memoize(std::vector<int> &arr,
        std::vector<std::vector<const bool*>> &cache, int index, int sum)
{
    std::vector<const bool*> &cached = cache[index];

    if(cached[sum]!= nullptr) {
        return *cached[sum];
    }

    bool isfind;
    if ( index <= 0 ) {
        isfind = arr[index]==sum;
    } else {
        if ( arr[index] > sum ) {
            isfind = subset_memoize(arr, cache, index-1, sum);
        } else if ( arr[index] == sum ) {
            isfind = true;
        } else {
            isfind = subset_memoize(arr, cache, index-1, sum-arr[index]) ||
                subset_memoize(arr, cache, index-1, sum);
        }
    }

    cached[sum] = isfind ? &EXIST:&NoEXIST;
    return isfind;
}

bool subset_dynamic(std::vector<int> &arr, int sum) {
    vector< vector<const bool*> > cache(arr.size(), vector<const bool*>(sum+1, nullptr));
    vector<const bool *> &cache0 = cache[0];

    for(auto &ele : cache0) { ele = &NoEXIST; }

    cache0[arr[0]] = &EXIST;

    for(int i=1; i<int(cache.size()); i++) {

        auto &currentcache = cache[i];

        currentcache[0] = &EXIST;

        for (int j=1; j<int(currentcache.size()); j++) {
            auto &lastcached = cache[i-1];

            if(j==arr[i]) {
                currentcache[j] = &EXIST;
            } else if (j > arr[i] ) {
                currentcache[j] = ( *(lastcached[j]) || *(lastcached[j-arr[i]]) )? &EXIST:&NoEXIST;
            } else { // j < arr[j]
                currentcache[j] = lastcached[j];
            }
        }
    }

    show2dvect(arr, cache);

    return *(cache[arr.size()-1][sum]);
}

void show2dvect(vector<int> &arr,const vector<vector<const bool *>> &vec) {
    int row = 0;
    std::for_each(vec.cbegin(), vec.cend(), [&row, &arr](std::vector<const bool*> v) {

            printf("index:%d=%-3d,", row, arr[row]);
            row++;

            int col = 0;
            std::for_each(v.cbegin(), v.cend(), [&col](const bool *bvalue) {
                    std::cout << col++ << ":" << ((bvalue!=nullptr)?((*bvalue)?"1":"0"):"-") << ", ";
                    });
            std::cout<<std::endl;
            });
}

