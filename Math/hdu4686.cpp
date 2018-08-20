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
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
struct Matrix
{
	int n,m;
	LL d[10][10];
	Matrix(int a = 0,int b = 0)
	{
		n = a;
		m = b;
		CL(d);
	}
	void copy(LL *temp){
		for (int i = 0;i < n;i++){
			for (int j = 0;j < m;j++){
				d[i][j] = *temp;
				temp++;
			}
		}
	}
	friend Matrix operator * (Matrix a,Matrix b)
	{
		Matrix c(a.n,b.m);
		LL temp;
		for (int i = 0;i < a.n;i++){
			for (int j = 0;j < b.m;j++){
				temp = 0;
				for (int k = 0;k < a.m;k++){
					temp = (temp + a.d[i][k] * b.d[k][j])%MOD;
				}
				c.d[i][j] = temp;
			}
		}
		return c;
	}
};
LL a0,ax,ay,b0,bx,by;
LL solve(LL n)
{
	a0%=MOD,ax%=MOD,ay%=MOD,b0%=MOD,bx%=MOD,by%=MOD;
	if (n == 1) return (a0*b0)%MOD;
	Matrix a(1,5);
	Matrix b(5,5);
	LL aa[5] = {0,a0*b0%MOD,a0,b0,1};
	LL bb[5*5] = {
		1,0,0,0,0,
		1,ax*bx%MOD,0,0,0,
		0,ax*by%MOD,ax,0,0,
		0,ay*bx%MOD,0,bx,0,
		0,ay*by%MOD,ay,by,1
	};
	a.copy(aa);
	b.copy(bb);
	while (n){
		if (n&1)
			a = a*b;
		b = b*b;
		n>>=1;
	}
	return a.d[0][0];
}
int main()
{
	LL n;
	while (scanf("%lld",&n) != EOF){
		cin>>a0>>ax>>ay;
		cin>>b0>>bx>>by;
		LL ans = solve(n);
		cout<<ans<<endl;
	}


	return 0;
}
