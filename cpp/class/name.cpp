#include<iostream>
#include<cstdlib>

using namespace std;

/*****************************
步骤一:成员申明的名字查找
1.balance1()的返回类型Money:
  1)由于balance1()是类内第一条申明，所以类内查找名字Money失败；
  2)在类外找到了声明，Money为int类型的别名；
2.balance1()的返回类型Money:
  1)balance2()之前在类内又申明了一次类型别名Money，(如果通过编译)所以balance2的返回类型为double
3.bal成员变量的类型Money查找同2，为double

步骤二:函数体的名字查找
4.在编译器处理完申明后，再处理函数体，返回bal变量的名字查找：
  1)函数体在申明后处理，所以bal是类的成员变量
*****************************/

typedef int Money;

class Account{
public:
	Money balance1(){return bal;}
	typedef double Money;//一些编译器会报错
	Money balance2(){return bal;}
private:
	Money bal = 1.234;
};

int main()
{
	Account ac;

	//上面注释中的名字处理步骤可以解释下列的结果

	cout << ac.balance1() << endl;//1
	cout << ac.balance2() << endl;//1.234

	return EXIT_SUCCESS;
}