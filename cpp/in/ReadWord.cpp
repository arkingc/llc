#include<string>
#include<iostream>

using namespace std;

int main()
{
	string word;
	/*
	 * 单词读取
	 *		每回车一次将一行返回给cin
	 *		空格被作为分隔符
	 */
	while(cin >> word){
		cout<<word<<endl;
	}
}
