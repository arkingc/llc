#include<iostream>

using namespace std;

/******************
 4.const与函数
 实参初始化形参时，顶层const会被忽略，所以调用fcn或fcn1时会出错
 是重复声明，不算重载
 *****************/

void fcn(const int i);
void fcn(int i);

void fcn1(int *const i);
void fcn1(int *i);

int main(){

	/*****************
	 1.常量（必须初始化）
	 *****************/

	int i = 1;
	const int i1 = 2; //编译时初始化
	const int i2 = i; //运行时初始化，初始值可以是任意复杂的表达式
	int i3 = i2;
	//const int i4;//错误，必须初始化


	/******************
	 2.const与指针
	 *****************/

	int a = 1;
	int b = 2;

	/*2.1:指向常量的指针，并不一定指向常量，这里常量的意思是无法通过指针修改指向的对象（可以不初始化）*/
	const int *a1 = &a; //a.
	//int *a2 = a1; //错误，不能将指向常量的指针作为指向非常量指针的初始化对象
	int const *a2 = &a; //b.和1等价，是指向常量的指针

	/*2.2:在const前，const指针（常量指针，必须初始化）*/
	int *const a3 = &a; 
	const int *a5;


	/******************
	 3.const与引用（必须初始化）
	 *****************/

	string s("hello world");
	string &s1 = s;//s1是s的别名
	//相当于:string &s2 = s
	string &s2 = s1;//s2是s的另一个别名
	const string &s5 = s2;

	//相当于:
	//const string tmp = "hello world"; 
	//const string &3 = tmp;
	const string &s3 = "hello world";
	//string &s4 = s3;//错误，不能将常量引用作为非常量应用的初始化对象
	//相当于:const string &s4 = tmp;
	const string &s4 = s3;//s4是tmp的另一个别名

	return 0;
}