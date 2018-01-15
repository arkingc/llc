#include<string> //有getline()函数
#include<iostream>

using namespace std;

int main()
{
	string line;
	/*
	 * 行读取
	 *	如果希望整行整行保存输入
	 *	换行符也会被读入cin，但是不会保存到line中
	 */
	while(getline(cin,line)){
		cout<<line<<endl;
	}
}
