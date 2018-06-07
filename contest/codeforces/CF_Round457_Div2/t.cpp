#include <iostream>
#include <cmath>
using namespace std;
int check(int t)
{
	int tt=sqrt(t);	
	for (int i=2;i<tt;++i)
		if (t%i==0)
			return 0;
	return 1;
}
int main()
{
	int t=1e5+5;
	while (!check(t)){
		++t;
	}
	cout<<t;
	return 0;
}
