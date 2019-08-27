//
// Created by zl on 2019-08-23.
//

#include "utils.h"

void display_vect(vector<int> &vect, std::unordered_map<int, std::string> *alias) {
    for(int v : vect) {
        if(!alias) { std::cout << v << " ";
        } else {
            string sv = (*alias)[v];

            if(sv=="") { sv = std::to_string(v); }

            sv += "";
            std::cout << sv+" ";
        }
    }
    std::cout <<  std::endl;
}

void display_map(std::unordered_map<string, int> &m, unordered_map<int, string> *alias) {
    for(auto i : m) {
        if(!alias && alias->empty()) {
            printf("%s:%2d, ", i.first.c_str(), i.second);
        } else {
            unordered_map<int, string>::iterator ite = alias->find(i.second);

            string second;
            if (ite==alias->end()) {
                second = std::to_string(i.second);
            } else {
                second = ite->second;
            }
            printf("%s:%s, ", i.first.c_str(), second.c_str());
        }
    }
}
