#include<iostream>
#include<cstdlib> //EXIT_SUCCESS

using namespace std;

/*********************
返回(指向)数组(的)指针
	1.
	 1)typedef
	 2)using
	2.decltype
	3.尾置返回类型：auto func(parameter_list) -> type(*)[dimension]
		为了表示真正的返回类型跟在形参列表之后，在函数返回类型的位置放置一个auto
	4.type (*func(parameter_list)) [dimension]
		func(parameter_list)：      表示调用func时需要parameter_list参数
		(*func(parameter_list))：   表示可以对调用结果指向解引用
		(*func(parameter_list)) [dimension]：表示解引用将得到大小是dimension的数组
		type (*func(parameter_list)) [dimension]：表示数组元素的类型为type
*********************/

int odd[] = {1,3,5,7,9};//奇数数组
int even[] = {0,2,4,6,8};//偶数数组

//两者等价
typedef int arrT1[5];
using arrT2 = int[5];
arrT1* arrPtr1(int i);//1.typedef/using

decltype(odd) *arrPtr2(int i);//2.decltype，C++11
auto arrPtr3(int i) -> int(*)[5];//3.尾置返回类型，C++11
int (*arrPtr4(int)) [5];//4


int main()
{
	arrT2 *r1,*r2,*r3,*r4;

	r1 = arrPtr1(0);//pointer to even
	r2 = arrPtr2(1);//pointer to odd 
	r3 = arrPtr3(2);//pointer to even
	r4 = arrPtr4(3);//pointer to odd


	cout << (*r1)[0] << endl;//0
	cout << (*r2)[0] << endl;//1
	cout << (*r3)[0] << endl;//0
	cout << (*r4)[0] << endl;//1

	return EXIT_SUCCESS;
}

arrT1* arrPtr1(int i)
{
	return i % 2 ? &odd : &even;
}

decltype(odd) *arrPtr2(int i)
{
	return i % 2 ? &odd : &even;
}

auto arrPtr3(int i) -> int(*)[5] {
	return i % 2 ? &odd : &even;
}

int (*arrPtr4(int i)) [5] {
	return i % 2 ? &odd : &even;
}