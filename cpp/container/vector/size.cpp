#include <iostream>
#include <vector>

using namespace std;

class test{
public:
    test() {cout << "test constructor" << endl;}
};

int main()
{
    vector<test> v;
    cout << "capacity:" << v.capacity() << "  size:" << v.size() << endl;   //capacity:0  size:0

    v.push_back(test());    //test constructor
    cout << "capacity:" << v.capacity() << "  size:" << v.size() << endl;   //capacity:1  size:1

    v.push_back(test());    //test constructor
    cout << "capacity:" << v.capacity() << "  size:" << v.size() << endl;   //capacity:2  size:2

    v.push_back(test());    //test constructor
    cout << "capacity:" << v.capacity() << "  size:" << v.size() << endl;   //capacity:4  size:3

    v.reserve(8);
    cout << "capacity:" << v.capacity() << "  size:" << v.size() << endl;   //capacity:8  size:3

    v.resize(6);    //test constructor（3次）
    cout << "capacity:" << v.capacity() << "  size:" << v.size() << endl;   //capacity:8  size:6

    v.reserve(7);   //reserve只能减小不能增大？
    cout << "capacity:" << v.capacity() << "  size:" << v.size() << endl;   //capacity:8  size:6

    v.resize(3);    //会释放3个对象，调用3次析构函数
    cout << "capacity:" << v.capacity() << "  size:" << v.size() << endl;   //capacity:8  size:3

    return 0;
}