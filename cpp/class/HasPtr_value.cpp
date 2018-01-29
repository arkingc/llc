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

HasPtr& HasPtr::operator= (const HasPtr &rhs)
{
    //要处理自赋值以及异常情况下能将左侧对象置于一个有意义的状态
    auto newp = new string(rhs.ps);
    delete ps;
    ps = newp;
    i = rhs.i;
    return *this;
}

