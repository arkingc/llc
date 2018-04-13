/**************************************************
 *    C++结构体大小根据以下条件进行计算:
 *    a. 结构体的大小等于结构体内最大成员大小的整数倍
 *    b. 结构体内的成员的首地址相对于结构体首地址的偏移量是其类型大小的整数倍
 *       (比如说double型成员相对于结构体的首地址的地址偏移量应该是8的倍数)
 *    c. 为了满足规则1和2编译器会在结构体成员之后进行字节填充
 *    d. 64位系统遵循8字节对齐，32位遵循4字节对齐
 *************************************************/

struct S1
{
    char    c1;
    char    c2;
    short   s;
    int     i;
};

struct S2
{
    char    c;
    int     i;
    short   s;
};

union U1 {
    char c;
    int i[2];
    double v;
};

union U2 {
    char c[9];
    int i[2];
    double v;
};

int main(){

    cout << sizeof(char) << endl;           //1
    cout << sizeof(short) << endl;          //2
    cout << sizeof(int) << endl;            //4
    cout << sizeof(double) << endl;         //8

    //struct
    cout << sizeof(struct S1) << endl;      //8
    cout << sizeof(struct S2) << endl;      //12

    //union
    cout << sizeof(U1) << endl;              //8
    cout << sizeof(U2) << endl;              //16

    return 0;
}