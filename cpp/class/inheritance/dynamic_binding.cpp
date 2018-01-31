//
// Created by 陈希明 on 18/1/26.
// 编译器:c++
//

#include <iostream>

using namespace std;

struct Base {
    virtual void info_virtual() {cout << "基类虚函数" <<endl;}
    void info() {cout << "基类非虚函数" <<endl;}
};

struct Derived : public Base {
    void info_virtual() {cout << "派生类1虚函数" << endl;}
    void info() {cout << "派生类1非虚函数" << endl;}
};

struct Derived2 : public Base {
    void info_virtual() {cout << "派生类2虚函数" << endl;}
    void info() {cout << "派生类2非虚函数" << endl;}
};

int main()
{
    Base b;
    Derived d;
    Derived2 d2;

    Base *bp;       //基类指针

    //1.测试虚函数的动态绑定
    bp = &b;
    bp->info_virtual(); //基类虚函数

    bp = &d;
    bp->info_virtual(); //派生类1虚函数

    bp = &d2;
    bp->info_virtual(); //派生类2虚函数

    //2.测试非虚函数是否会动态绑定
    bp = &b;
    bp->info();         //基类非虚函数

    bp = &d;
    bp->info();         //基类非虚函数

    bp = &d2;
    bp->info();         //基类非虚函数

    //3.通过派生类的指针无法访问被覆盖的基类成员(包括虚函数和非虚函数)
    Derived *dp = &d;       //派生类1指针
    Derived2 *d2p = &d2;    //派生类2指针

    dp -> info();           //派生类1非虚函数
    dp -> info_virtual();   //派生类1虚函数
    d2p -> info();          //派生类2非虚函数
    d2p -> info_virtual();  //派生类2虚函数

    return EXIT_SUCCESS;
}