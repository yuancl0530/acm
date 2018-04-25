/*********************************
Date: Fri Aug 25 20:40:39 CST 2017
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
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e3 + 100;
int sum[maxn][maxn];
int n;
int lowbit(int x){return x&(-x);}
void update(int x,int y,int value)
{
	for (int i=x;i<=n;i+=lowbit(i)){
		for (int j=y;j<=n;j+=lowbit(j)){
			sum[i][j]+=value;
		}
	}
}
LL query(int x,int y)
{
	LL ret=0;
	for (int i=x;i>0;i-=lowbit(i)){
		for (int j=y;j>0;j-=lowbit(j)){
			ret+=sum[i][j];
		}
	}
	return ret;
}
int op;
int main()
{
	return 0;
}
