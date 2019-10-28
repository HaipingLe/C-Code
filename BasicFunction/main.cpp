#include <iostream>
#include <queue>

/************function declaration***************/
void testConstructor();
void testCopyConstructor();
void testMoveConstructor1();
void testMoveConstructor2();

void testAssignmentOperator();
void testMoveAssignmentOperator();
/************function declaration***************/

/**********************************class declaration**********************************************************/
class Complex
{
public:
    Complex()
    {
        std::cout << "call constructor without parameters" << std::endl;
        mReal = new double(0.0);
        mImag = new double(0.0);
    }

    Complex(double real, double imag)
    {
        std::cout << "call constructor with parameters" << std::endl;
        mReal = new double(real);
        mImag = new double(imag);
    }

    ~Complex()
    {
        std::cout << "call de-constructor" << std::endl;
        if (mReal)
        {
            delete mReal;
        }

        if (mImag)
        {
            delete mImag;
        }
    }
 
    Complex(const Complex &c)
    {
        std::cout << "call copy-constructor" << std::endl;
        //对象能否访问到私有成员与其定义的位置有关：在类内定义，可以访问，在类外定义，不能访问!
        mReal = new double(*(c.mReal));
        mImag = new double(*(c.mImag));
    }

    Complex &operator=(Complex &rhs)
    {
        std::cout << "call assignment operator" << std::endl;
        if (this == &rhs)
        {
            return *this;
        }

        *(this->mReal) = *(rhs.mReal);
        *(this->mImag) = *(rhs.mImag);

        return *this;
    }

    //move constructor
    Complex(Complex &&rhs)
    {
        std::cout << "call move constructor" << std::endl;
        mReal = rhs.mReal;
        rhs.mReal = nullptr;
        mImag = rhs.mImag;
        rhs.mImag = nullptr;
    }

    //Move assignment operator
    Complex &operator=(Complex &&rhs)
    {
        std::cout << "call move assignment operator" << std::endl;
        if (this == &rhs)
        {
            return *this;
        }
        //Free the existing resource.
        delete this->mReal;
        delete this->mImag;

        this->mReal = rhs.mReal;
        rhs.mReal = nullptr;

        this->mImag = rhs.mImag;
        rhs.mImag = nullptr;
    }

private:
    double *mReal;
    double *mImag;
};
/**********************************class declaration*****************************************************************/


void testConstructor()
{
    Complex c1;
    Complex c2(1, 1);
    Complex *c3 = new Complex();
    delete c3;
}

void testCopyConstructor()
{
    Complex c1(1, 1);
    Complex c2(c1);

    //Note:It won't use assignment operator.
    Complex c3 = c2;
}

void testMoveConstructor1()
{
    Complex c1(1, 1);
    Complex &&c2 = std::move(c1);
    Complex c3(c2);
    Complex c4(std::move(c1));
    Complex c5(std::move(c2));
}

void testMoveConstructor2()
{
    Complex c1(1, 1);
    std::queue<Complex> q;
    q.emplace(c1);
    q.emplace(std::move(c1));
}

void testAssignmentOperator()
{
    Complex c1(1, 1);
    Complex c2;
    Complex c3;
    c2 = c1;
    c3.operator=(c1);
}

void testMoveAssignmentOperator()
{
    Complex c1(1, 1);
    Complex c2;
    c2 = std::move(c1);
}

int main()
{
    std::cout<<"****************Hello, Haiping!***************"<< std::endl;
    std::cout<<""<< std::endl;
#if 1
    std::cout<<"************testConstructor  Begin***************"<< std::endl;
    testConstructor();
    std::cout<<"************testConstructor  End*****************"<< std::endl;
#endif

#if 0
    std::cout << "************testCopyConstructor  Begin***************" << std::endl;
    testCopyConstructor();
    std::cout << "************testCopyConstructor  End*****************" << std::endl;
#endif

#if 0
    std::cout << "************testMoveConstructor1  Begin***************" << std::endl;
    testMoveConstructor1();
    std::cout << "************testMoveConstructor1 End*****************" << std::endl;
#endif

#if 0
    std::cout << "************testMoveConstructor2  Begin***************" << std::endl;
    testMoveConstructor2();
    std::cout << "************testMoveConstructor2 End*****************" << std::endl;
#endif

#if 0
    std::cout << "************testAssignmentOperator  Begin***************" << std::endl;
    testAssignmentOperator();
    std::cout << "************testAssignmentOperator  End*****************" << std::endl;
#endif

#if 0
    std::cout << "************testMoveAssignmentOperator  Begin***************" << std::endl;
    testMoveAssignmentOperator();
    std::cout << "************testMoveAssignmentOperator  End*****************" << std::endl;
#endif

    return 0;
}