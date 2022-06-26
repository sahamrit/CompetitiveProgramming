#include<iostream>
using namespace std;
struct complex_no{
int real,comp;
complex_no(const complex_no &a)
{
    real=a.real;
    comp=a.comp;
}
complex_no(){}
complex_no(int r,int c):real(r),comp(c){}
friend complex_no& operator +(complex_no &a,complex_no &b);
};
complex_no& operator +(complex_no&a,complex_no&b)
{complex_no *c=new complex_no;
c->real=a.real+b.real;
c->comp=a.comp+b.comp;
return  *c;

}

int main()
{
    complex_no a(2,3);
    complex_no b(4,5);
    complex_no c=a+b;
    cout<<c.real<<" "<<c.comp;
}
