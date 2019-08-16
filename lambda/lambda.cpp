#include <stdlib.h>
#include <cstdlib>
#include <vector>
#include <iostream>

// https://en.wikipedia.org/wiki/Anonymous_function#C++_(since_C++11)


class Test {
private:
    int m_value = 10;
public:
    void foo();
    void display();
};

void Test::foo() {
    auto x = [&,this](void) -> int {
        std::cout << "my value = " << m_value << std::endl;
        int tmp_vlaue = m_value - 5;
        m_value = 2;
        return tmp_vlaue;
    };

    int ret_value = x();
    std::cout << "x returned value = " << ret_value << std::endl;
}
void Test::display() {
    std::cout << "Test::display()->Test.m_value = " << m_value << std::endl;
}

// Here is an example of storing anonymous functions in variables,
// vectors, and arrays; and passing them as named parameters:
double eval(std::function <double(double)> f, double x = 2.0) {
	return f(x);
}

int example_storing_anonymous_functions_in_variables() {
	std::function<double(double)> f0    = [](double x){return 1;};
	auto                          f1    = [](double x){return x;};
	decltype(f0)                  fa[3] = {f0,f1,[](double x){return x*x;}};
	std::vector<decltype(f0)>     fv    = {f0,f1};
	fv.push_back                  ([](double x){return x*x;});

	for(int i=0; i < (int)fv.size(); i++)
		std::cout << fv[i](2.0) << std::endl;

	for(int i=0;i<3;i++)
		std::cout << fa[i](2.0) << std::endl;

	for(auto &f : fv)
		std::cout << f(2.0) << std::endl;

	for(auto &f : fa)
		std::cout << f(2.0) << std::endl;

	std::cout << eval(f0) << std::endl;
	std::cout << eval(f1) << std::endl;
	std::cout << eval([](double x){return x*x;}) << std::endl;
	return 0;
}

auto add(int x, int y) -> int {
    return x+y;
}

int main(int argc, char* argv[]) {
    printf("2 + 3 = %d\n", add(2,3));

    example_storing_anonymous_functions_in_variables();
    return 0;

    Test t;
    t.foo();

    t.display();


    std::vector<int> some_list{ 1, 2, 3, 4, 5 };
    int total = 0;

    std::for_each(begin(some_list), std::end(some_list), [&total](int x) {
            total += x;
            });
    std::cout << "total=" << total << std::endl;

    total = 0;
    int value = 5;
    std::for_each(begin(some_list), end(some_list), [&, value](int x) {
            total += x * value;
            });

    std::cout << "total=" << total << std::endl;
}


