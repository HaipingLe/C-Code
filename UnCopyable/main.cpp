#include <iostream>

class CUnCopyable
{
protected:
    CUnCopyable()
    {
        std::cout << "Call CUnCopyable constructor" << std::endl;
    }
    virtual ~CUnCopyable() {}

/*Note:
To avoid copying operation, we can daclare the copy constructer and the assignment function as delete in C++ 11.
We also have another solution, we can declare the copy constructer and the assignment function as pravite member and we don not implement it.
*/
#if 0
    CUnCopyable(const CUnCopyable &) = delete;
    CUnCopyable &operator=(const CUnCopyable &) = delete;
#endif
private:
#if 1
    CUnCopyable(const CUnCopyable &);
    CUnCopyable &operator=(const CUnCopyable &);
#endif
};

class Test : public CUnCopyable
{
public:
    Test()
    {
        std::cout << "Call Test()" << std::endl;
        a = 0;
    }

    Test(int x)
    {
        std::cout << "Call Test(int)" << std::endl;
        a = x;
    }

    //Note : Because Test is designed to avoid copying operation, theres is no need to define our own copy constructor.
    // Test(const Test &)
    // {
    //     std::cout << "Call Test Copy Constructor" << std::endl;
    // }

    ~Test()
    {
        std::cout << "Call ~Test()" << std::endl;
    }

private:
    int a;
};

int main()
{
    Test test1(1);
    std::cout << "copy test1 to test2." << std::endl;
    Test test2(test1);

    return 0;
}
