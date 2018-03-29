#include<iostream>


/*
 * Y,Z虚继承X
 * A普通继承Y,Z
 */
class X{};
class Y:public virtual X{};
class Z:public virtual X{};
class A:public Y,public Z{};

int main()
{

	//64位下的结果为：1，8，8，16
    cout << "sizeof(X) : " << sizeof(X) << endl;
    cout << "sizeof(Y) : " << sizeof(Y) << endl;
    cout << "sizeof(Z) : " << sizeof(Z) << endl;
    cout << "sizeof(A) : " << sizeof(A) << endl;

    return EXIT_SUCCESS;
}