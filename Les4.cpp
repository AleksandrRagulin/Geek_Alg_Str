#include <iostream>
#include <math.h>
using namespace std;
void fun1(int a);
int fun2(int a,int b);
int main()
{
	//fun1(16);
	cout << fun2(3,4);
	return 0;
}

void fun1(int a){
	if (a<2) cout << a;
	else
	{
		fun1(a/2);
		cout << a%2;
	}
}
int fun2(int a, int n)
{

 	if (n==0)
 	{
  		return 1;
 	}
 	if(n%2==0) 
 	{
 		a=a*a;
 		return a*fun2(a, n/2-1);
 	}
 	else return a*fun2(a, n-1);
}
