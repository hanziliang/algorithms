#include <iostream>
using namespace std;

// refer to https://www.cnblogs.com/likaiming/p/9029908.html [right value reference]
// refer to https://www.cnblogs.com/64open/p/5270991.html [std::forward]

class A {
    public:
        A():m_ptr(new int(0)){ cout << "construct" << endl; }
        A(int v):m_ptr(new int(v)) { cout << "construct" << endl; }
        A(const A& a):m_ptr(new int(*a.m_ptr)) {
            cout << "copy construct" << endl;
        }

        A(A&& a):m_ptr(a.m_ptr) {
            a.m_ptr = nullptr;
            cout << "move construt" << endl;
        }

        ~A(){
            cout << "destory" << endl;
            delete m_ptr;
        }

        void showValue() {
            if (this->m_ptr==nullptr) {
                cout << "m_ptr is set to nullptr by 'move-construct'" << endl;
                return;
            }
            cout << "my value is:" << (*m_ptr) << endl;
        }
    private:
        int* m_ptr;
};

constexpr int X() {
    return 20;
}

int a = 3;

constexpr int Get(int value) {
    return value;
};

A Get_A() {
    return A(2);
}

#define __func_prefix__     \
    cout<<">>>>>>>>>>>>>>> "<<__func__<<" <<<<<<<<<<<<<<<"<<endl;

// c++中临时变量默认const属性,所以只能传给const的引用.
// this expression will cause an error
// A& class_a1 = A(1)
// 规定右值不能绑定到非 const 限定的左值引用.
void test_0() {
    __func_prefix__
    A&&  class_a = Get_A();
    __func_prefix__
    A  class_b = Get_A();
}

void test_1() {
    __func_prefix__
    A a(1);
    A b = static_cast<A&&>(a);
    A c = static_cast<A&&>(A(2));
    __func_prefix__
    A d = Get_A();
}

void test_2(int&& a ) {
    __func_prefix__
    int i = 0;
    int &ri = i;

    // 右值绑定时会把所有的单个变量都看成变量表达式,
    // 然而单个变量的表达式返回的是一个左值引用,然而右值引用无法绑定到左值引用,
    // 最终造成的结果是我们无法把一个右值引用直接绑定到另一个右值引用上,
    // 就像下面的代码会出现编译错误:
    // rvalue reference to type 'int' cannot bind to lvalue of type 'int'
    // int &&a_ref = a;
    // 等价于:
    // int &&a_ref = (a)

    cout <<  boolalpha;
    cout << is_same<decltype(ri), int&>::value << endl;           //true
    cout << is_same <int, decltype(i)>::value << endl;            //true
    cout << is_same <double, decltype(3 + 4.0)>::value << endl;   //true
    cout << is_same <int&, decltype((i))>::value << endl;         //true
    cout << is_same <int, decltype(3 + 4)>::value << endl;        //true
    cout << is_same<int&,  decltype((a))>::value << endl;         //true
    cout << is_same<int&&, decltype((a))>::value << endl;         //false
    cout << is_same<int&&, decltype((int&&)(a))>::value << endl;  //false
    cout << is_same<int&&, decltype(a)>::value << endl;
}

void g(int &&) { cout << "right reference" << endl; }
void g(const int&) { cout << "left reference" << endl; }

void test_3(int&& a ) {
    __func_prefix__

    g(a); // this will get:left reference
    // this will get: right refrence
    g((int&&)(a));
    g(std::move(a));
    g(std::forward<int>(a));
}


template <typename T>
void f (T&& arg) { g ( std::forward<T>(arg) ); }
void test_4() {
    __func_prefix__
        int i = 0;
    int &ri = i;
    int &&rri = 4;
    f(i);
    f(ri);
    f(0);
    f(std::move(i));

    // 实际上 f 收到的是左值引用, 右值引用只能绑定到 右值 上,
    // 而不能绑定到另一个右值引用上,左值引用却可以绑定到另一个右值引用或者另一个左值引用或者左值上
    f(rri);
}

int main() {
    const std::vector<int> v{1};
    auto a = v[0];        // a has type int
    decltype(v[0]) b = 1; // b has type const int&, the return type of


    test_0();
    test_1();
    test_2(10);

    test_3((int&&)(10));
    test_4();

    return 0;

}


