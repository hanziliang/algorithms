#include "bind.template.h"

class BindTest {
public:
    static void execute()
    {
        auto f = std::bind([](int a, char b, const char *c)
                {
                std::cout << "std::bind_test:" << a << b << c << std::endl;
                }, 1, 'a', "abc");
        f();

        int teswt = 12;
        auto f2 = _bind([](int a, char b, const char *c)
                {
                std::cout << "_bind_test:" << a << b << c << std::endl;
                }, teswt, 'a', "abc" );
        f2();
    }
};

class X {
    public:
        X(int x):_x(x) {};
        int _x;
        void display() { printf("X.display(), _x vlaue = %d\n", _x); };
};

int main ( int argc, char *argv[] )
{
    X the_x(20);

    auto x = std::reference_wrapper<X>(the_x);
    ((X&)x).display();
    ((X&)x)._x++;

    the_x.display();


    BindTest::execute();
    return EXIT_SUCCESS;
}
