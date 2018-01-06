#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
int gcd(int a,int b)
{
	if (b==0)return a;
	return gcd(b,a%b);
}
int f(int a,int b)
{
	int ret = a/b;
	if (ret*b!=a)
		ret++;
	return ret;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++){
		int s = 0;
		for (int j = 1;j <= i;j++){
			int t = gcd(i,j);
			if (t!=1)cout<<"   ";
			else printf("%2d ",f(i,j));
			if (t==1)
				s+=f(i,j);
		}
		cout <<"*"<<s<< endl;
	}


	return 0;
}
