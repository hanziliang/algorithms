/*
 * =====================================================================================
 *
 *       Filename:  explicitly.defaulted.and.deleted.special.member.functions.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  03/21/2019 19:16:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <string>
typedef int OTHERTYPE;

class SomeType
{
    SomeType() = default; //The default constructor is explicitly stated.
    SomeType(OTHERTYPE value);
};

//Alternatively, certain features can be explicitly disabled. For example, this type is non-copyable:
class TestClass
{
    private:
        int value = 0;
public:
    const char *name;
    TestClass() { value = 1; name = "null"; } ;//  = default;
    // ~TestClass() = delete;

    TestClass(const TestClass& t) {
        printf("copy constructor is call\n");
        value = t.value;
    }

    TestClass(std::initializer_list<int> l) {
        printf("initializer_list constructor is call\n");
        this->value = *l.begin();
    };

    TestClass(TestClass &&t):value(t.value),name(t.name) {
        t.name = nullptr;
        printf("move constructor is call.\n");
    }

    TestClass& operator =(const TestClass& t) {
        printf("operator = is called\n");
        value = t.value;
        return *this;
    }

    void Disaplay() { printf("%s.value = %d\n", name, value); };

    TestClass& operator++() // ++x
    {
        printf("++%s is called\n", name);
        ++value;
        return *this;
    }

    TestClass operator++(int) // x++
    {
        printf("%s++ is called\n", name);
        TestClass tmp = *this;

        char *buff = new char[20];
        memset(buff, 0, 20);
        sprintf(buff, "%s++.Display()", name);
        tmp.name = buff;
        value++;
        return tmp;
    }
};

int main(void) {
    // TestClass(std::initializer_list<int> l) {};
    printf("----------------------------------------\n");
    TestClass *a = new TestClass;
    TestClass *b = new TestClass[5];
    //TestClass *c = static_cast<TestClass*>(::operator new(sizeof(TestClass)));
    // c->TestClass::TestClass();

    TestClass x = {2};

    printf("----------------------------------------\n");
    // placement new, 重复使用已经分配好的内存,
    // 避反复的分配, 释放内存, 导致内存碎片化问题
    TestClass *c = new(&x) TestClass();
    c->name = "c";
    c->Disaplay();
    printf("actually x.Display() is called, now 'x' and 'c' is pointed to the same address..\n");
    x.Disaplay();
    printf("----------------------------------------\n");

    x.name = "x";
    printf("----------------------------------------\n");
    TestClass y = x;
    y.name = "y";
    x.Disaplay();
    y.Disaplay();
    printf("----------------------------------------\n");
    x++.Disaplay();
    x.Disaplay();
    printf("----------------------------------------\n");
    (y = x).Disaplay();
    printf("----------------------------------------\n");
    (++x).Disaplay();
    printf("----------------------------------------\n");
    x++.Disaplay();
    x.Disaplay();
    printf("----------------------------------------\n");
}
