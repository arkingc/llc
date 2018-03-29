/*
 *   A的对象                  虚函数表
 *  --------       ---------------------------
 * |  vptr  | --> | A::a | A::b | A::c | A::d |
 *  --------       ---------------------------
 */
class A{
public:
    virtual void a() {cout << "a() in A" << endl;}
    virtual void b() {cout << "b() in A" << endl;}
    virtual void c() {cout << "c() in A" << endl;}
    virtual void d() {cout << "d() in A" << endl;}
};

/*
 *   B的对象                  虚函数表
 *  --------       ---------------------------
 * |  vptr  | --> | B::a | B::b | A::c | A::d |
 *  --------       ---------------------------
 */
class B : public A{
public:
    void a() {cout << "a() in B" << endl;}
    void b() {cout << "b() in B" << endl;}
};

/*
 *   C的对象                  虚函数表
 *  --------       ---------------------------
 * |  vptr  | --> | C::a | C::b | A::c | A::d |
 *  --------       ---------------------------
 */
class C : public A{
public:
    void a() {cout << "a() in C" << endl;}
    void b() {cout << "b() in C" << endl;}
};

/*
 *    D的对象                  虚函数表
 *  -----------       ---------------------------
 * |  B::vptr  | --> | D::a | B::b | A::c | D::d |
 *  -----------       ---------------------------
 * |  C::vptr  | --> | D::a | C::b | A::c | D::d |
 *  -----------       ---------------------------
 */
class D : public B,public C{
public:
    void a() {cout << "a() in D" << endl;}
    void d() {cout << "d() in D" << endl;}
};