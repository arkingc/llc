//
// Created by 陈希明 on 18/1/26.
// 编译器:c++
//

#include <iostream>

using namespace std;

class test{
public:
    test(const char *str) {cout << "转换构造函数" << endl;}
    test(const test &t) {cout << "拷贝构造函数" << endl;}

    string s;
};

int main()
{
    /*
     * 实际上这句代码分2步：
     * 1）调用转换构造函数构造一个临时对象
     * 2）使用临时对象作为参数调用拷贝构造函数构造t
     *
     * 但是编译器因为效率等原有可以(但不是必须)绕过拷贝构造函数：
     * 1）直接转换为：test t("hello world"); 即只调用转换构造函数来直接构造t
     * 但是即使绕过，拷贝构造函数也必须是存在且可访问的(如，不能是private)。因为
     * 理论上是需要这一步的。
     */
    test t = "hello world";//输出：转换构造函数
    test t2 = t; //输出：拷贝构造函数

    return EXIT_SUCCESS;
};