// this src illustrate the new definition of POD in c++11
// refer to:https://blog.csdn.net/aqtata/article/details/35618709
#include <iostream>

using namespace std;

#define TRIVAIL_OBJECTS 1
#define STANDARD_LAYOUT 0

#if TRIVAIL_OBJECTS

class A { A(){} };
class B { B(B&){} };
class C { C(C&&){} };
class D { D& operator=(D&){ return *this; } };
class E { E& operator=(E&&){ return *this; } };
class F { ~F(){} };
class G { virtual void foo() = 0; };
class H : G {};
class I {};

void display() {
	std::cout << std::is_trivial<A>::value << std::endl;  // 有不平凡的构造函数
	std::cout << std::is_trivial<B>::value << std::endl;  // 有不平凡的拷贝构造函数
	std::cout << std::is_trivial<C>::value << std::endl;  // 有不平凡的拷贝赋值运算符
	std::cout << std::is_trivial<D>::value << std::endl;  // 有不平凡的拷贝赋值运算符
	std::cout << std::is_trivial<E>::value << std::endl;  // 有不平凡的移动赋值运算符
	std::cout << std::is_trivial<F>::value << std::endl;  // 有不平凡的析构函数
	std::cout << std::is_trivial<G>::value << std::endl;  // 有虚函数
	std::cout << std::is_trivial<H>::value << std::endl;  // 有虚基类
	std::cout << std::is_trivial<I>::value << std::endl;  // 平凡的类
}

#elif STANDARD_LAYOUT

class A { private: int a; public: int b; };
class B1 { static int x1; };
class B2 { int x2; };
class B : B1, B2 { int x; };
class C1 {};
class C : C1 { C1 c; };
class D { virtual void foo() = 0; };
class E : D {};
class F { A x; };

void display() {
	std::cout << std::is_standard_layout<A>::value << std::endl;  // 违反定义1。成员a和b具有不同的访问权限
	std::cout << std::is_standard_layout<B>::value << std::endl;  // 违反定义2。继承树有两个(含)以上的类有非静态成员
	std::cout << std::is_standard_layout<C>::value << std::endl;  // 违反定义3。第一个非静态成员是基类类型
	std::cout << std::is_standard_layout<D>::value << std::endl;  // 违反定义4。有虚函数
	std::cout << std::is_standard_layout<E>::value << std::endl;  // 违反定义5。有虚基类
	std::cout << std::is_standard_layout<F>::value << std::endl;  // 违反定义6。非静态成员x不符合标准布局类型
}

#else
void dispay() {}
#endif

int main(int argc, char* argv[])
{
    display();
	return 0;
}
