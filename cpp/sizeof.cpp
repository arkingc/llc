#include <iostream>

using namespace std;

void Test(int Array[],int Size)
{
    //作为参数传递时，数组作为指针，sizeof(Array) == 8
    int Num = sizeof(Array) / sizeof(int);
    for(int i = 0;i < Num && i < Size;i++){
        cout << Array[i] << " ";
    }
    cout << endl;
}

int main(){

    char *string1 = "tencent2018";
    int size1 = sizeof(string1);            //8
    int size2 = sizeof(*string1);           //1
    char string2[100] = "tencent2018";
    int size3 = sizeof(string2);            //100，并不是把string2当成一个指针处理
    char string3[] = "hello";               
    int size4 = sizeof(string3);            //6，保存结尾\0

    int arr1[] = {1,2,3,4};
    int arr2[10] = {1};
    cout << sizeof(arr1) << endl;           //16，没有当作指针
    cout << sizeof(arr2) << endl;           //40，没有当作指针

    Test(arr1, sizeof(arr1)/sizeof(int));

    return 0;
}