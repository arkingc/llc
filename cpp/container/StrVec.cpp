//
// Created by 陈希明 on 18/1/26.
// 编译器:c++
//

#include <iostream>
#include <memory>

using namespace std;

/*
 * 一个简单的vector实现
 * 非模板，用来存string元素，重点在于理解动态内存类的空间管理，以及类的拷贝控制函数(拷贝构造函数，赋值拷贝运算符，析构)
 */

class StrVec {
public:
    StrVec() : elements(nullptr) , first_free(nullptr) , cap(nullptr) {}
    StrVec(const StrVec&);              //拷贝构造函数
    StrVec & operator=(const StrVec&);  //拷贝赋值运算符
    ~StrVec();                          //析构函数
    void push_back(const string&);      //添加元素
    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}
    string * begin() const {return elements;}
    string * end() const {return first_free;}
private:
    static allocator<string> alloc; //分配元素的静态allocator对象
    void chk_n_alloc() {if (size() == capacity()) reallocate();}
    //alloc_n_copy会分配足够的内存来保存给定范围的元素，并将这些元素拷贝至新分配内存中
    //返回pair的first成员指向新空间的开始位置，second成员指向拷贝的尾后的位置
    pair<string*,string*> alloc_n_copy(const string*,const string *);
    void free();        //销毁元素并释放内存
    void reallocate();  //获得更多内存并拷贝已有元素
    string *elements;   //指向数组首元素的指针
    string *first_free; //指向数组第一个空闲元素的指针
    string *cap;        //指向数组尾后位置的指针
};

void StrVec::push_back(const string &s)
{
    chk_n_alloc();//确保有空间容纳新元素
    //在first_free指向的元素中构造s的副本
    alloc.construct(first_free++,s);
}

pair<string*,string*> StrVec::alloc_n_copy(const string *b, const string *e)
{
    //根据需要拷贝的元素范围，分配空间
    auto data = alloc.allocate(e - b);
    //拷贝元素并返回pair
    return {data,uninitialized_copy(b,e,data)};
}

//首先destroy元素，然后释放走自己分配的内存
void StrVec::free()
{
    if(elements){
        //逆序销毁元素
        for(auto p = first_free; p != elements;){
            alloc.destroy(--p);
        }
        alloc.deallocate(elements,cap - elements);
    }
}

//拷贝构造函数
StrVec::StrVec(const StrVec &s)
{
    //调用alloc_n_copy分配空间以容纳与s中一样多的元素
    auto newdata = alloc_n_copy(s.begin(),s.end());
    elements = newdata.first;
    //因为alloc_n_copy分配的空间恰好容纳给定的元素，所以cap也指向最后一个构造元素之后的位置
    first_free = cap = newdata.second;
}

StrVec::~StrVec() { free(); }

void StrVec::reallocate()
{
    //将分配当前大小2倍的空间
    auto newcapacity = size() ? 2 * size() :1;
    //分配新内存
    auto newdata = alloc.allocate(newcapacity);
    //将数据从旧内存移动到新内存
    auto dest = newdata;    //指向新数组中下一个元素
    auto elem = elements;   //指向旧数组中下一个元素
    for(size_t i = 0;i != size();++i)
        alloc.construct(dest++,std::move(*elem++));
    free(); //完成元素的移动后释放旧内存空间
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

//拷贝赋值运算符
StrVec & StrVec::operator=(const StrVec &rhs)
{
    //调用alloc_n_copy分配内存，大小与rhs中的元素占用空间一样多
    auto data = alloc_n_copy(rhs.begin(),rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}
