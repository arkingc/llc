class Test1{
public:
    Test1() {cout << "Test1 constructor" << endl;}
    ~Test1() {cout << "Test1 destructor" << endl;}
};

class Test2{
public:
    Test2() {cout << "Test2 constructor" << endl;}
    ~Test2() {cout << "Test2 destructor" << endl;}
};

class Base{
public:
    Base () {cout << "Base constructor" << endl;}
    ~Base() {cout << "Base destructor" << endl;}
private:
    Test1 t1;
    Test2 t2;
};

int main()
{
    /*************
     * Output:
     * Test1 constructor
     * Test2 constructor
     * Base constructor
     * Base destructor
     * Test2 destructor
     * Test1 destructor
     *************/
    Base b;
}