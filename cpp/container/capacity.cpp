#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

int main()
{
	vector<string> v = {"hello","world"};

	cout << "size:" << v.size() << "  capacity:" << v.capacity() << endl;//2 2

	v.push_back("world");

	cout << "size:" << v.size() << "  capacity:" << v.capacity() << endl;//3 4

	v.reserve(1);

	cout << "size:" << v.size() << "  capacity:" << v.capacity() << endl;//3 4 

	return EXIT_SUCCESS;
}