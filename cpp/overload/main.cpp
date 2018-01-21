
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

/************************
底层const重载
注：1）底层const即不能改变所指对象，所以传入常量和非常量都没有问题。
   故如果传入非常量或者指向非常量的指针，重载的函数都能调用，但是对于编译器优先选择非const版本
   传入常量或指向常量的指针时，只能选择const版本
   2）如果没有重载非const版本，但是当传入一个非常量实参时希望返回一个非常量引用，则需对调用
      结果进行const_cast转换。const_cast能转换底层const，但是如果传入的实参是一个常量，
      转换后修改的话结果未定义。同时这种方式也会加重调用者的负担
*************************/

const string &shorterString(const string &s1,const string &s2);

string &shorterString(string &s1,string &s2);

int main()
{
	string s1(5,'l');
	string s2(10,'h');

	string &s3 = shorterString(s1,s2);//调用非const版本

	cout << s3 << endl;

	return EXIT_SUCCESS;
}

const string &shorterString(const string &s1,const string &s2){
	return s1.size() <= s2.size() ? s1 : s2;
}

string &shorterString(string &s1,string &s2){
	return s1.size() <= s2.size() ? s1 : s2;
}