/*
 * =====================================================================================
 *
 *       Filename:  knapsack.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  08/16/2019 17:41:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#include "knapsack.h"

int snapsack_recursion(vector<int> &weights, vector<int> &values, int index, int cap) {
    // let us assume that 'index' never be negative
#if 0
    if(index==0) {
        return cap >= weights[0] ? values[0]:0;
    } else { //  if(index>0) {
        if (cap >= weights[index] ) {
            return max(snapsack_recursion(weights, values,index-1,  cap-weights[index]) + values[index],
                    snapsack_recursion(weights, values, index-1, cap) );
        } else {
            return snapsack_recursion(weights, values, index-1, cap);
        }
    }
#else
    return index==0?(weights[0]<=cap?values[0]:0):( weights[index]>cap ?
            snapsack_recursion(weights, values, index-1, cap) :
            max(snapsack_recursion(weights, values, index-1, cap-weights[index]) + values[index],
                snapsack_recursion(weights, values, index-1, cap) ));
#endif
}

int snapsack_dp(vector<int> &weights, vector<int> &values, int cap) {
    int size = values.size();
    std::vector<std::vector<int> > maxValue(size+1, vector<int>(cap+1,0));

    for(int i=1; i<=size; i++) {
        printf("i=%d ==> ", i);
        for (int icap=1; icap<=cap; icap++) {
            if ( icap<weights[i-1] ) {
                maxValue[i][icap] = maxValue[i-1][icap];
            } else {
                maxValue[i][icap] = max(maxValue[i-1][icap],
                        maxValue[i-1][icap - weights[i-1]] + values[i-1]);
            }
            printf("%d ", maxValue[i][icap]);
        }
        printf("\n");
    }

    return maxValue[size][cap];
}
