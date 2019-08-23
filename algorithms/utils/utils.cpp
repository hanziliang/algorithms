//
// Created by 曾亮 on 2019-08-23.
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

