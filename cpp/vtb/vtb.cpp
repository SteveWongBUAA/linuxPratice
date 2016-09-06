#include <iostream>
#include <cstdlib>
using namespace std;

class Base {
public:
    virtual void f() { cout << "Base::f" << endl; }
    virtual void g() { cout << "Base::g" << endl; }
    virtual void h() { cout << "Base::h" << endl; }
    
};

class Derive: Base
{
    virtual void f() { cout << "Derive::f" << endl; }
    virtual void g1() { cout << "Derive::g1" << endl; }
    virtual void h1() { cout << "Derive::h1" << endl; }
};


int main(void)
{
    typedef void(*Fun)(void);
    
    Base b;
    
    Fun pFun = NULL;
    
    cout << "虚函数表地址：(long*)(&b)" << (long*)(&b) << endl;
	long* pvtb = (long*)(&b);
    cout << "虚函数表 - 第一个函数地址：(long*)*(long*)(&b): " << (long*)*(long*)(&b) << endl;
    cout << "虚函数表 - 第一个函数地址：(long*)pvtb[0]: " << (long*)pvtb[0] << endl;
    cout << "虚函数表 - 第二个函数地址：(long*)*(long*)(&b)+1: " << (long*)*(long*)(&b)+1 << endl;
    cout << "虚函数表 - 第三个函数地址：(long*)*(long*)(&b)+2: " << (long*)*(long*)(&b)+2 << endl;
    
    // Invoke the first virtual function
    pFun = (Fun)*((long*)*(long*)(&b));
    pFun();
	pFun = (Fun)*((long*)pvtb[0]);
	pFun();
    pFun = (Fun)*((long*)*(long*)(&b)+1);  // Base::g()
    pFun();
    pFun = (Fun)*((long*)*(long*)(&b)+2);  // Base::h()
    pFun();

	Derive d;

    cout << "多态：\n虚函数表地址：(long*)(&d)" << (long*)(&d) << endl;
    cout << "虚函数表 - 第1个函数地址：(long*)*(long*)(&d): " << (long*)*(long*)(&d) << endl;
    cout << "虚函数表 - 第2个函数地址：(long*)*(long*)(&d)+1: " << (long*)*(long*)(&d)+1 << endl;
    cout << "虚函数表 - 第3个函数地址：(long*)*(long*)(&d)+2: " << (long*)*(long*)(&d)+2 << endl;
    cout << "虚函数表 - 第4个函数地址：(long*)*(long*)(&d)+3: " << (long*)*(long*)(&d)+3 << endl;
    cout << "虚函数表 - 第5个函数地址：(long*)*(long*)(&d)+4: " << (long*)*(long*)(&d)+4 << endl;
    
    // Invoke the first virtual function
    pFun = (Fun)*((long*)*(long*)(&d));
    pFun();
    pFun = (Fun)*((long*)*(long*)(&d)+1);  
    pFun();
    pFun = (Fun)*((long*)*(long*)(&d)+2); 
    pFun();
    pFun = (Fun)*((long*)*(long*)(&d)+3); 
    pFun();
    pFun = (Fun)*((long*)*(long*)(&d)+4); 
    pFun();

    return 0;
}
