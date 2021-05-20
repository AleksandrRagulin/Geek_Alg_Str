#include <iostream>
using namespace std;
bool isSimple(int a)
{	
	if (a < 3) return true;
	for (int i = 2;i <= a/2;++i)
	{
		if(a%i==0) return false;
	}
	return true;
}
int main(int argc,char* argv[])
{
	int x = atoi(argv[1]);
	cout << x << endl;
	if(isSimple(x)) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}
