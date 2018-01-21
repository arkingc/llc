#include<iostream>
#include<cstdlib> //EXIT_SUCCESS

using namespace std;

/*********************
返回(指向)函数(的)指针
	1.
	 1)typedef
	 2)using
	2.decltype（用于获取函数类型）
	3.尾置返回类型：auto func(parameter_list) -> type(*)(parameter_list_r)
		为了表示真正的返回类型跟在形参列表之后，在函数返回类型的位置放置一个auto
		*表明返回的是个指针
		(parameter_list_r)表明是个函数，参数为parameter_list_r
		type是函数的返回类型
	4.type (*func(parameter_list)) (parameter_list_r)
		func(parameter_list)：      表示调用func时需要parameter_list参数
		(*func(parameter_list))：   表示可以对调用结果执行解引用，说明结果是一个指针
		(*func(parameter_list)) (parameter_list_r)：表示指针指向一个函数
		type (*func(parameter_list)) (parameter_list_r)：表示返回指针指向函数的返回类型为type
*********************/

//提供给decltype，获取函数类型

string::size_type sumLength(const string &s1,const string &s2);
string::size_type largerLenght(const string &s1,const string &s2);

//函数类型别名

typedef string::size_type fcnT1(const string &s1,const string &s2);//fcnT1是函数类型
using fcnT2 = string::size_type(*)(const string &s1,const string &s2);//fcnT2是指向函数的指针,去掉*则等价于上一行

//返回(指向)函数(的)指针的函数声明

fcnT1* fcnPtr1(int i);

decltype(sumLength) *fcnPtr2(int i);
auto fcnPtr3(int i) -> string::size_type(*)(const string &s1,const string &s2);
string::size_type (*fcnPtr4(int i)) (const string &s1,const string &s2);


int main()
{
	cout << fcnPtr1(0)("hhh","lll") << endl;//fcnPtr1(0)返回指向largerLenght的指针,输出3
	cout << fcnPtr2(1)("hhh","lll") << endl;//fcnPtr2(1)返回指向sumLength的指针,输出6
	cout << fcnPtr3(2)("hhh","lll") << endl;//fcnPtr3(2)返回指向largerLenght的指针,输出3
	cout << fcnPtr4(3)("hhh","lll") << endl;//fcnPtr4(3)返回指向sumLength的指针,输出6
	//等价于
	cout << (*fcnPtr1(0))("hhh","lll") << endl;
	cout << (*fcnPtr2(1))("hhh","lll") << endl;
	cout << (*fcnPtr3(2))("hhh","lll") << endl;
	cout << (*fcnPtr4(3))("hhh","lll") << endl;
}

fcnT1* fcnPtr1(int i)
{
	//&可以去掉
	//当把函数名作为一个值使用时，该函数自动地转换成指针
	return i % 2 ? &sumLength : &largerLenght;
}

decltype(sumLength) *fcnPtr2(int i)
{
	return i % 2 ? &sumLength : &largerLenght;
}

auto fcnPtr3(int i) -> string::size_type(*)(const string &s1,const string &s2)
{
	return i % 2 ? &sumLength : &largerLenght;
}

string::size_type (*fcnPtr4(int i)) (const string &s1,const string &s2)
{
	return i % 2 ? &sumLength : &largerLenght;
}

//sumLength与largerLenght的定义

string::size_type sumLength(const string &s1,const string &s2){
	return s1.size() + s2.size();
}

string::size_type largerLenght(const string &s1,const string &s2){
	return s1.size() >= s2.size() ? s1.size() : s2.size(); 
}