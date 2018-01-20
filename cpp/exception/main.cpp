#include<iostream>

using namespace std;

void div();

int main(){
	
	int a,b;

	try{
		div();			
	}catch (runtime_error err){//在这捕获
		cout<<err.what()<<endl;
	}

	return 0;
}

void div()
{
	int a,b;
	if(cin >> a >> b){
		try{
			if(b == 0)
				throw runtime_error("除数不能为0!");
			else
				cout<<a/b<<endl;
			return;
		}catch (range_error e) {//不会捕获
			cout<<e.what()<<endl;
		}
	}

	cout<<"error input!"<<endl;
}
