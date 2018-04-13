#include <iostream>

using namespace std;

/***************************************************************
 * 1）typeid表达式的形式是typeid(e)，e可以是任意表达式或类型的名字
 * 2）顶层const会被忽略
 * 3）作用于数组或函数时，并不会执行向指针的标准类型转换，即对数组a执行type(a)
 *    得到的是数组类型而非指针类型
 ***************************************************************/

struct base{
};

struct child : public  base{
};

struct basevirtual{
public:
    virtual void print() {cout << "base" << endl;}
};

struct childvirtual : public  basevirtual{
};

int main(){
    /***************************************************************
     * 1.当运算对象不属于类类型或者是一个不包含任何虚函数的类时，
     *   typeid运算符指示的是运算对象的静态类型
     ***************************************************************/

    base b;
    child c;
    base *pb = &b;
    base *pc = &c;
    cout << typeid(pb).name() << endl;     //P4base
    cout << typeid(pc).name() << endl;     //P4base
    cout << typeid(*pb).name() << endl;    //4base
    cout << typeid(*pc).name() << endl;    //4base

    /***************************************************************
     * 2.当运算对象是定义了至少一个虚函数的类的左值时，
     *   typeid的结果直到运行时才会求得
     ***************************************************************/

    basevirtual bv;
    childvirtual cv;
    basevirtual *pbv = &bv;
    basevirtual *pcv = &cv;
    cout << typeid(pbv).name() << endl;     //P11basevirtual
    cout << typeid(pcv).name() << endl;     //P11basevirtual
    //运行时求得
    cout << typeid(*pbv).name() << endl;    //11basevirtual
    cout << typeid(*pcv).name() << endl;    //12childvirtual

    return 0;
}