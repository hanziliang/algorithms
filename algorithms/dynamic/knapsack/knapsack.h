/*
 * =====================================================================================
 *
 *       Filename:  knapsack.h
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  08/16/2019 17:40:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <vector>
using namespace std;

int snapsack_recursion(vector<int> &weights, vector<int> &values, int index, int cap);
int snapsack_dp(vector<int> &weights, vector<int> &values, int cap);
