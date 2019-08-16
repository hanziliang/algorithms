#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct Minus {
    int operator() (int i, int j) {
        return i - j;
    }
};

std::vector<int> vec = {10, 20, 35, 77, 68};

auto it = std::find_if(vec.begin(), vec.end(), [](int i) { return i > 50; });
class A {
public:
    bool operator()(int i) const {
        cout<< "i=" << i <<endl;
        return i > 50;
    }
};


int main()
{
#if 0
    std::vector<int>::iterator iti = std::find_if(vec.begin(), vec.end(), A());
#else
    cout<< "-----------------------1" << endl;
    A x;

    cout<< "-----------------------2" << endl;
    function<bool(int)> f5 = std::bind(&A::operator(), x, placeholders::_1);

    cout<< "-----------------------3" << endl;
    // the type of 'iti' is 'std::vector<int>::iterator'
    auto iti = std::find_if(vec.begin(), vec.end(), x);

    cout<< "-----------------------4" << endl;
    vector<int>::iterator itii = std::find_if(vec.begin(), vec.end(), f5);

    cout<< "-----------------------5" << endl;

#endif
    cout<< "-----------------------6" << endl;
    if(iti != vec.end()) std::cout<< *iti << endl;

    cout<< "-----------------------7" << endl;
    if(itii != vec.end()) std::cout << *itii << std::endl;

    cout<< "-----------------------8" << endl;
    cout << x(89) << endl;

    cout<< "-----------------------9" << endl;
    cout << Minus()(1, 2) << endl;

    cout<< "-----------------------0" << endl;
    function<int(int, int)> f = [](int i, int j) {return i-j;};
    function<int(int, int)> f_1 = Minus();
    cout << f(1, 2) << endl;
    return 1;
}
