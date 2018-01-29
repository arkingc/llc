//
// Created by 陈希明 on 18/1/26.
// 编译器:c++
//

#include <iostream>

using namespace std;

/*
 * <自定义行为像值的类>
 * 每个对象都有自己的数据成员的拷贝
 */

class HasPtr{
    //自定义的swap(如果一个类定义了自己的swap，那么算法将使用类自定义版本，否则将使用标准库定义的swap)
    friend void swap(HasPtr&,HasPtr&);
public:
    //构造函数
    HasPtr(const string &s = string()) :
            ps(new string(s)) , i(0) {}
    //拷贝构造函数
    HasPtr(const HasPtr &p) :
            ps(new string(p.ps)) , i(p.i) {}
    //拷贝赋值运算符
    HasPtr& operator=(const HasPtr &);
    //析构函数
    ~HasPtr() {delete ps;}

private:
    string *ps;
    int i;
};

//运用swap的拷贝赋值运算符，具有如下优点：
//1、自动处理了自赋值的情况，能保证其正确
//2、天然就是异常安全的
HasPtr& HasPtr::operator= (HasPtr rhs)
{
    //在传参时，就已经拷贝了一个临时对象，这个临时对象的ps成员申请了一块动态内存
    //swap交换了当前对象和这个临时对象ps成员的指针，以及i的值
    //当函数返回后，参数销毁，析构函数释放了原本这个对象ps成员申请的动态内存
    swap(*this,rhs);
    return *this;
}

//swap并不是必要的，但是对于分配了资源的类，定义swap可能是一种很重要的优化手段
inline void swap(HasPtr &lhs,HasPtr &rhs)
{
    //如果using std::swap后交换的成员自定义了swap操作，则会优先匹配其自定义的swap，否则调用std::swap
    using std::swap;
    swap(lhs.ps,rhs.ps);
    swap(lhs.i,rhs.i);
}