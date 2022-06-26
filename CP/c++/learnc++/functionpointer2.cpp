// A simple C program to show function pointers as parameter
#include <iostream>
using namespace std;

// Two simple functions
void fun1(int a) { cout<<"fn1\n";
    cout<<a;
}
void fun2(int a) { cout<<"fn2\n";
 cout<<a; }

// A function that receives a simple function
// as parameter and calls the function
void wrapper(void (*fun)(int ),int a)
{
	fun(a);
}

int main()
{
	wrapper(&fun1,2);
	wrapper(fun2,3);
	return 0;
}
