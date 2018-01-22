#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class HelloWorld
{
public:
	HelloWorld () {}//要定义const对象需要自定义默认构造函数
	//1.非常量对象会调用这个版本
	HelloWorld& display(ostream &os)
		{do_display(os); return *this;}
	//2.常量对象会调用这个版本
	const HelloWorld& display(ostream &os) const
		{do_display(os); return *this;}

	HelloWorld& modify(const string &s)
		{info = s; return *this;}

private:
	void do_display(ostream &os) const {os << info << endl;}
	string info = "hello world";
};

int main()
{
	HelloWorld h1;
	const HelloWorld h2;

	//调用的是第1个版本的display函数，返回的是非常量引用，所以可以调用modify
	h1.display(cout).modify("hhhh").display(cout);
	//调用的是第2个版本的display函数，返回的是常量引用，不能调用modify
	h2.display(cout);
	//h2.display(cout).modify("hhhh").display(cout);//错误

	return EXIT_SUCCESS;
}