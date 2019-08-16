// http://www.cnblogs.com/lysuns/p/4278589.html
#include <stdlib.h>
#include <string>
#include <iostream>
#include <vector>

struct IdString
{
    std::string name;
    int identifier;
};

IdString get_string()
{
    return {"foo", 42};
}

#include <vector>
#include <initializer_list>
#include <iterator>

template <class T>
class S {
    public:
        std::vector<T> v;
        S() { std::cout << "default constructor is call" << std::endl; };
        S(const S &) { std::cout << "copy constructor is call" << std::endl; }
        S(const S &&) { std::cout << "move constructor is call" << std::endl; }
        //S(std::initializer_list<T> l) : v(l) {
            //std::cout << "initializer_list constructor..." << l.size() << "-element list"<<std::endl;
        //}

        S<T>& operator =(S<T>&& str) { std::cout << "operator = (S<T>&&) is call " << std::endl; return *this; }
        S<T>& operator =(const S<T>& str) { std::cout << "operator = (const S<T>&) is call " << std::endl; return *this; }

        ~S() { std::cout<<"delete "<<this<<std::endl; }
        S(std::initializer_list<T> l) {
            typedef typename std::initializer_list<T>::iterator s_iterator;
            //for (typename std::initializer_list<T>::iterator i=l.begin; i!=l.end(); ++i) {
            //for (auto i=l.begin(); i!=l.end(); ++i) {
            //for (s_iterator i=l.begin(); i!=l.end(); ++i) {
            for (const T* i=std::begin(l); i!=std::end(l); ++i) {
                std::begin(l);
                v.push_back(*i);
            }
            std::cout << "constructed with a " << l.size() << "-element list\n";
        }

        //S(std::initializer_list<T> l) {
        //for (const T* i=std::begin(l); i!=std::end(l); ++i) {
        //std::cout << "i = " << *i << std::endl;
        //v.push_back(*i);
        //}
        //std::cout << "constructed with a " << l.size() << "-element list\n";
        //}

        void append(std::initializer_list<T> l) {
            v.insert(v.end(), l.begin(), l.end());
        }
        std::pair<const T*, std::size_t> c_arr() const {
            return {&v[0], v.size()};  // copy list-initialization in return statement
            // this is NOT a use of std::initializer_list
        }

        void display() {
            for (T& t:v) {
                std::cout<< t ;
            }
            std::cout<<std::endl;
        }
};


class MyNumber {
    public:
        MyNumber(const std::initializer_list<int> &v) {
            for (auto itm : v) { mVec.push_back(itm); }
        }

        void print() {
            for (auto itm : mVec) { std::cout << itm << " "; }
        }
    private:
        std::vector<int> mVec;
};

template <typename T>
void templated_fn(T) {}

void rvalue_example() {
    std::cout << "--------------" << std::endl <<
        "rvalue examples" << std::endl <<
        "operator="<<std::endl <<
        "copy constructor"<<std::endl <<
        "move constructor" <<std::endl <<
        "initializer_list" <<std::endl << "-------------------\n";
    std::initializer_list<std::string> il {"hello", "world"};

    S<std::string> s(il);
    S<std::string> s2 = S<std::string>{"will", "call move constructor"};
    std::cout << "-----------------------------" << std::endl;
    S<std::string> s3 = std::move(S<std::string>{"will", "call over load operator = &&"});
    S<std::string> s4 = s3;
    std::cout << "-----------------------------" << std::endl;
    s3 = S<std::string>{"will", "call over load operator = &&"};
    s4 = s3;
    std::cout << "----------------rvalue example end-------------" << std::endl;

    for (auto n : s.v)
        std::cout << n << ' ';
    std::cout << '\n';
}

int main()
{
    std::cout<< " hello world!!!" << std::endl;
    rvalue_example();

    S<int> s = {1, 2, 3, 4, 5}; // copy list-initialization
    s.append({6, 7, 8});      // list-initialization in function call
    std::cout << "The vector size is now " << s.c_arr().second << " ints:\n";


    std::cout << "Range-for over brace-init-list: \n";

    for (int x : {-1, -2, -3}) // the rule for auto makes this ranged-for work
        std::cout << x << ' ';
    std::cout << '\n';

    auto al = {10, 11, 12};   // special rule for auto

    std::cout << "The list bound to auto has size() = " << al.size() << '\n';

//    templated_fn({1, 2, 3}); // compiler error! "{1, 2, 3}" is not an expression,
                             // it has no type, and so T cannot be deduced
    templated_fn<std::initializer_list<int>>({1, 2, 3}); // OK
    templated_fn<std::vector<int>>({1, 2, 3});           // also OK


    std::vector<int> the_vec{4};
    // double f2{ 1e40 }; //error

    IdString ids1 = get_string();
    IdString ids2{"foo", 42};
    //IdString ids3("foo", 42);
    IdString ids4 = {"foo", 42};

    printf("ids {name:%s, id:%d}\n", ids1.name.c_str(), ids1.identifier);
    printf("ids {name:%s, id:%d}\n", ids2.name.c_str(), ids2.identifier);
    //printf("ids {name:%s, id:%d}\n", ids3.name.c_str(), ids3.identifier);
    printf("ids {name:%s, id:%d}\n", ids4.name.c_str(), ids4.identifier);
}
