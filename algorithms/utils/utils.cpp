//
// Created by zl on 2019-08-23.
//

#include "utils.h"

INT_ALIAS ALIAS = {{INF, "INF"}, {0, "NAN"},};

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


vector<int> scan_int_array() {
    const int size = 256;

    const char *splitor = " ";

    vector<int> arr;
    char input[size] = {0};
    cout<< "input arrary number split by space..." << endl;

    cin.getline(input, size-1);

    int length = strlen(input);

    for(int i=0; i<length; i++){
        if((input[i]>'9' || input[i]<'0') && input[i]!=32 && input[i]!=0x2d) {
            printf("there is a invalid char, index:%d, value:0x%x('%c')\n", i, input[i], input[i]);
            return arr;
        }
    }
    input[length] = '\0';

    char *findpos = input;

    while(true){
        char *tmppos = strstr(findpos, splitor);

        if( tmppos==nullptr ) {
            break;
        }

        if(tmppos!=findpos) {
            tmppos[0] ='\0';
            arr.push_back(atoi(findpos));

        }

        findpos = tmppos+1;
    }

    if(findpos[0]!='\0') {
        arr.push_back(atoi(findpos));
    }

    return arr;
}
