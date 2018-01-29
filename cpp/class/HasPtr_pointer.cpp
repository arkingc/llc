//
// Created by 陈希明 on 18/1/26.
// 编译器:c++
//

#include <iostream>

using namespace std;

/*
 * <自定义行为像指针的类>
 * 拷贝指针本身而不是它指向的对象，因此所有对象指向相同的动态成员对象；
 * 只有最后一个对象销毁时，才能释放动态成员对象；
 * 拷贝时需要增加引用计数；
 * 唯一的难题是确定在哪存放引用计数，需要保证所有对象看到的引用计数一致。一种方法是使用动态对象来保存引用计数
 */

class HasPtr{
public:
    //构造函数
    HasPtr(const string &s = string()) :
            ps(new string(s)) , i(0) ,use(new size_t(1)){}
    //拷贝构造函数
    HasPtr(const HasPtr &p) :
            ps(p.ps) , i(p.i) , use(p.use){++*use;}
    //拷贝赋值运算符
    HasPtr& operator=(const HasPtr &);
    //析构函数
    ~HasPtr();

private:
    string *ps;
    size_t *use;
    int i;
};

//大多数拷贝赋值运算符组合拷贝构造函数和析构函数的工作
HasPtr& HasPtr::operator= (const HasPtr &rhs)
{
    //自赋值时，如果先递减则会释放，会出错。因此先递增
    ++*rhs.use;
    //析构函数的工作，如果原来动态成员对象的引用计数减为0，在更新前先完成释放工作
    if(*--use == 0){
        delete ps;
        delete use;
    }
    //拷贝构造函数的工作(包括最开始的递增)，更新成员已经递增引用计数
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

HasPtr::~HasPtr()
{
    //递减引用计数，最后一个销毁的对象会负责是释放动态内存
    if(*--use == 0){
        delete ps;
        delete use;
    }
}