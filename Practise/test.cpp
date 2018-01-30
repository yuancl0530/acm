#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char *a()
{
	char s[20]="123";
	return s;
}
int main()
{
	cout<<a()<<endl;
	printf("%s\n",a());
	return 0;
}
