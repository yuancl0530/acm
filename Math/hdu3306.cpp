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
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e4 + 7;
const int maxn = 1e6 + 100;
struct Matrix
{
	int n,m;
	int d[10][10];
	Matrix(int a= 0,int b = 0):n(a),m(b)
	{
		CL(d);
	}
	void copy(int *temp)
	{
		for (int i = 0;i < n;i++){
			for (int j = 0;j < m;j++){
				d[i][j] = *temp;
				++temp;
			}
		}
	}
	friend Matrix operator * (Matrix a,Matrix b)
	{
		Matrix c(a.n,b.m);
		LL temp;
		for (int i = 0;i < a.n;i++){
			for (int j =0;j < b.m;j++){
				temp = 0;
				for (int k = 0 ;k < a.m;k++){
					temp = (temp + a.d[i][k] * b.d[k][j]) % MOD;
				}
				c.d[i][j] = temp;
			}
		}
		return c;
	}
};
LL solve(LL n,LL x,LL y)
{
	if (n==0)return 1;
	if (n==1)return 2;
	x%=MOD;
	y%=MOD;
	Matrix a(1,4);
	Matrix b(4,4);
	int aa[4] = {1,1,1,1};
	int bb[4*4] = {
		1,0,0,0,
		1,x*x%MOD,1,x,
		0,y*y%MOD,0,0,
		0,2*x*y%MOD,0,y
	};
	a.copy(aa);
	b.copy(bb);
	while (n){
		if (n&1) a = a*b;
		b = b*b;
		n>>=1;
	}
	return a.d[0][0];
}
int main()
{
	LL n,x,y;
	while (scanf("%lld%lld%lld",&n,&x,&y) != EOF){
		LL ans = solve(n,x,y);
		printf("%lld\n",ans);
	}
	return 0;
}
