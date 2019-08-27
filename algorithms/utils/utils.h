//
// Created by 曾亮 on 2019-08-23.
//

#ifndef ALGORITHMS_UTILS_H
#define ALGORITHMS_UTILS_H

#include <vector>
#include <iostream>
using namespace std;

#include <unordered_map>

void display_vect(vector<int> &vect, std::unordered_map<int, std::string> *alias=nullptr);
void display_map(std::unordered_map<string, int> &m, unordered_map<int, string> *alias= nullptr);

#endif //ALGORITHMS_UTILS_H
