/*
 * =====================================================================================
 *
 *       Filename:  knapsack.example.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  08/19/2019 09:57:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */

#include "../dynamic/knapsack/knapsack.h"

int main(int argc, char* argv[]) {
    vector<int> weights = {1, 15, 20, 2, 4, 6, 5, 8};
    vector<int> values = {2, 2, 4, 1, 1, 3, 1, 1};

    time_t start, end;
    start = time(0);
    int totalValue = snapsack_recursion(weights, values, weights.size()-1, 20);
    end = time(0);

    printf(" snapsack_recursiontotalValue=%d, cost time=%f\n\n", totalValue, difftime(end, start));

    start = time(0);
    totalValue = snapsack_dp(weights, values, 20);
    end = time(0);

    printf("snapsack_dp totalValue=%d, cost time=%f\n", totalValue, difftime(end, start));
}
