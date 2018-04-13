//
// Created by 陈希明 on 09/2/26.
// 编译器:c++
//

#include <iostream>

using namespace std;

/*
 * 对于继承中的两个对象，如果类型相同并且对应数据成员相等，则我们说这两个对象相等；
 *
 * 容易想到用于实现相等运算符的一种方案是定义一套虚函数，令其在继承体系的各个层次上分别执行相等性判断，
 * 此时，可以为定义一个参数为基类类型引用的相等运算符函数，该函数将工作委托给虚函数equal，由equal负责
 * 实际相等比较；
 *
 * 但是，虚函数的基类版本和派生类版本必须具有相同形参类型，如果想定义一个虚函数equal，则该函数的形参必须
 * 是基类的引用，此时，equal函数将只能使用基类的成员，而不能比较派生类独有的成员；
 *
 * 对于上述问题，可以使用RTTI(运行时类型识别)解决；
 */

class Base{
public:
    Base() : a(0) {}
    Base(int e) : a(e) {}
    friend bool operator==(const Base &, const Base &);
protected:
    virtual bool equal(const Base&) const;
private:
    int a;
};

bool Base::equal(const Base &rhs) const
{
    return a == rhs.a;
}

class Derived : public Base{
public:
    Derived(int e) : Base() , b(e) {}
    Derived(int e1,int e2) : Base(e1) , b(e2) {}
protected:
    bool equal(const Base&) const;
private:
    int b;
};

bool Derived::equal(const Base &rhs) const
{
    //由于先进行了类型比较才调用equal，所以这里的转换是安全的
    auto r = dynamic_cast<const Derived&>(rhs);
    return b == r.b && Base::equal(r);
}

bool operator==(const Base &lhs,const Base &rhs)
{
    //先判断类型是否相等，再调用equal比较
    return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

int main()
{
    Base b1(1),b2(1),b3(2);
    // d1: a(0) b(2)
    // d2: a(1) b(2)
    // d3: a(1) b(2)
    Derived d1(2),d2(1,2),d3(1,2);

    cout << boolalpha ;

    //类型不同
    cout << "b1 == d1:" << (b1 == d1) << endl;//false
    //类型相同，但成员不相等
    cout << "b2 == b3:" << (b2 == b3) << endl;//false
    cout << "d1 == d2:" << (d1 == d2) << endl;//false
    //类型相同，且成员相等
    cout << "b1 == b2:" << (b1 == b2) << endl;//true
    cout << "d2 == d3:" << (d2 == d3) << endl;//true

    cout << noboolalpha << endl;

    return EXIT_SUCCESS;
}