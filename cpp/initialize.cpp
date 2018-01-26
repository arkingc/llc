//
// Created by 陈希明 on 18/1/26.
// 编译器:c++
//

#include <iostream>

using namespace std;

struct test{
public:
    string s;
    int i;
};

int global_i; //全局内置类型初始化为0
test global_t;

int main()
{
    int local_i; //局部内置类型不默认初始化，值未定义
    static int static_i; //静态内置类型值初始化，为0

    test local_t;
    static test static_t;

    cout << "global int:" << global_i << endl; //0
    cout << "local int:" << local_i << endl; //未定义
    cout << "static int:" << static_i << endl; //0

    cout << "global test:" << global_t.s << "," << global_t.i << endl; // "",0
    cout << "local test:" << local_t.s << "," << local_t.i << endl; // "",未定义
    cout << "static test:" << static_t.s << "," << static_t.i << endl; // "",0

    return EXIT_SUCCESS;
};