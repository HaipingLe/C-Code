#include <iostream>

class A
{
/*
The Virtual Table of Class A can be described as follows
--------------------------------
          A::~A()              
--------------------------------
          A::vfunc1()
--------------------------------
          A::vfunc2()
--------------------------------
*/
public:
    A()
    {
        std::cout << "Call A()" << std::endl;
    }

    virtual ~A()
    {
        std::cout << "Call ~A()" << std::endl;
    }

    virtual void vfunc1()
    {
        std::cout << "A::vfunc1" << std::endl;
    };

    virtual void vfunc2()
    {
        std::cout << "A::vfunc2" << std::endl;
    };

    void func1()
    {
        std::cout << "A::func1" << std::endl;
    };

    void func2()
    {
        std::cout << "A::func2" << std::endl;
    };
};

class B : public A
{
/*
The Virtual Table of Class B can be described as follows
--------------------------------
          B::~B()          
--------------------------------
          B:vfunc1()
--------------------------------
          A::vfunc2()
--------------------------------
*/
public:
    B()
    {
        std::cout << "Call B()" << std::endl;
    }

    virtual ~B()
    {
        std::cout << "Call ~B()" << std::endl;
    }

    virtual void vfunc1()
    {
        std::cout << "B::vfunc1" << std::endl;
    };

    void func1()
    {
        std::cout << "B::func1" << std::endl;
    };
};

class C : public B
{
/*
The Virtual Table of Class C can be described as follows
--------------------------------
          C::~C()      
--------------------------------
          B::vfunc1()   
--------------------------------
          C:vfunc2()
--------------------------------
*/
public:
    C()
    {
        std::cout << "Call C()" << std::endl;
    }

    ~C()
    {
        std::cout << "Call ~C()" << std::endl;
    }

    virtual void vfunc2()
    {
        std::cout << "C::vfunc2" << std::endl;
    };

    void func2()
    {
        std::cout << "C::func2" << std::endl;
    };
};

int main()
{
    A *pa;
    B b;
    pa = &b;
    std::cout << "When Pa points to b." << std::endl;
    pa->vfunc1();
    pa->vfunc2();
    pa->func1();
    pa->func2();
    std::cout << "When Pa points to c." << std::endl;
    C c;
    pa = &c;
    pa->vfunc1();
    pa->vfunc2();
    pa->func1();
    pa->func2();

    return 0;
}

/*
------------Result-------------
Call A()
Call B()
When Pa points to b.
B::vfunc1
A::vfunc2
A::func1
A::func2
When Pa points to c.
Call A()
Call B()
Call C()
B::vfunc1
C::vfunc2
A::func1
A::func2
Call ~C()
Call ~B()
Call ~A()
Call ~B()
Call ~A()
--------------------------------
*/