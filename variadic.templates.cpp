/*
 * =====================================================================================
        To Disable standard #include directories for the C++ standard library
        https://clang.llvm.org/docs/ClangCommandLineReference.html#cmdoption-clang1-nostdinc
 * =====================================================================================
 */
#include <iostream>

void printf_t(const char *s) {
    while (*s) {
        if (*s == '%' && *(++s) != '%')
            throw std::runtime_error("invalid format string: missing arguments");
        std::cout << *s++;
    }
}

template<typename... Args>
void show_argsize(Args ...args) {
    int the_size = sizeof...(args);
    std::cout << "the size = " << the_size << std::endl;
}

template<typename T, typename... Args>
void printf_t(const char* s, T value, Args... args) {
    while (*s) {
        if (*s == '%' && *(++s) != '%') {
            std::cout << value;
            printf_t(*s ? ++s : s , args...);
            return;
        }
        std::cout << *s++;
    }
    throw std::logic_error("extra arguments provided to printf_t");
}

template<class F, class... Args>
void expand(const F& f, Args&&...args) {
    // disable the following -Wunused-value warning..
    // compile with -Wno-unused-value or -Wno-unused, or you can
    // To suppress this warning, cast the 'unused' expression to `void`
    // https://gcc.gnu.org/onlinedocs/gcc-4.1.2/gcc/Warning-Options.html
    std::initializer_list<int>{(f(std::forward<Args>(args)), 0)...};
}

// Template aliases
template <typename First, typename Second, int Third>
float add(First f, Second s) {
    return float(f) + float(s) + Third;
}


template <typename First, typename Second, int Third>
class SomeType{
    public:
    First f;
    Second s;
    int x;
    int z;
    SomeType(First _f, Second _s, int _x):f(_f),s(_s),x(_x),z(Third){};
    void Display(){
        std::cout<< "first:" << f << ",second:" << s << ",x:" << x << ",z:" << z << std::endl;

    }
};

// C++11 adds this ability with this syntax:]
template <typename Second>
#if 1
using TypedefName = SomeType<const std::string&, Second, 5>;

// and this is ok
TypedefName<int> realcalss_(std::string("hello"), 5, 3);

#else   // will cause a compile error

template <typename Second>
typedef SomeType<std::string&, Second, int> TypedefName;

#endif


/*The using syntax can also be used as type aliasing in C++11:*/

typedef void (*FunctionType)(double);  // Old style
using FunctionType = void (*)(double); // New introduced syntax


int main(void) {
    show_argsize("abcdef", "x", "y");

    printf_t("hello world %a ||||| %c ||||| %x.\n", "one", "two", "three");

    expand([](int i){ std::cout<< i << "," << std::endl; }, 1, 2, 3);

    printf(R"any_string(hello \ world\"ni \n/)any_string" \
        "\nthis is a new line\n" \
        R"abcdef(yes\n]n\r")abcdef" \
        "\nthis is a new line" "\n");

    SomeType<const char*,int,5> realclass ("hello, ", 4, 4);
    SomeType<std::string,int,5> realclass1 (std::string("hello, "), 4, 4);

    realclass.Display();
    realclass1.Display();

    std::string s("hello world");
    std::cout << s << std::endl;

    printf("template add result=%f\n", add<int, float, 5>(10, 20.8));
    return 0;
}
