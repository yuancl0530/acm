/*********************************
Date: Fri Aug 25 19:08:26 CST 2017
*********************************/
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
int s[maxn];
int a[maxn];
int n;
int lowbit(int x)
{
	return x&(-x);
}
int query(int n)
{
	int sum=0;
	while (n>0){
		sum+=s[n];
		n-=lowbit(n);
	}
	return sum;
}
void update(int i,int value)
{
	while (i<=n){
		s[i]+=value;
		i+=lowbit(i);
	}
}
int main()
{
	
	return 0;
}
