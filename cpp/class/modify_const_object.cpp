class A{
public:
    A(const string &s) : str(s)
    {
        cstr = (char*)malloc(10);
        strcpy(cstr,"hello");
    }
    ~A() {free(cstr);}

    const string& getstr() const {return str;}      //const成员函数，如果不返回const引用，编译报错
    char& getcstr(int i) const {return cstr[i];}    //const成员函数，返回非const引用

    friend ostream& operator<<(ostream &os,const A &a);

private:
    string str;
    char* cstr;
};

ostream& operator<<(ostream &os,const A &a)
{
    os << "str:" << a.str << "    " << "cstr:" << a.cstr;
    return os;
}

int main()
{
    const A a("hello");
    cout << a << endl;//str:hello    cstr:hello

    //通过const成员函数最终也修改了对象
    a.getcstr(0) = 'j';
    cout << a << endl;//str:hello    cstr:jello

    return EXIT_SUCCESS;
}