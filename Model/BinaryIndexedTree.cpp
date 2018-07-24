#include <bits/stdc++.h>
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
int query(int pos)
{
	int sum=0;
	for (;n>0;pos-=lowbit(pos))
		sum+=s[pos];
	return sum;
}
void update(int pos,int value)
{
	for (;pos<=n;pos+=lowbit(pos))
		s[pos]+=value;
}
int main()
{
	return 0;
}
