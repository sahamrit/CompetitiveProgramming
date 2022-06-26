#include <iostream>

using namespace std;


class real{private :int x=0;
public: real(int a):x(a){}
         real(){}
         friend real operator+(int b,real &no);
         int getno()
         {
             return x;
         }
};
 real operator+(int b,real &no)
         {
             real newo;
             newo.x=b+no.x;
             return newo;
         }
int main()
{
    real obj(100),obj1;
    int var=20;
    obj1=var+obj;
    cout<<obj1.getno();
}
