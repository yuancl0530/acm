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
	Matrix(int a = 0,int b = 0)
	{
		n = a;
		m = b;
	}
	void copy(int *t)
	{
		for (int i = 0;i < n;i++){
			for (int j = 0;j < m;j++){
				d[i][j] = *t;
				t++;
			}
		}
	}
	friend Matrix operator * (Matrix a,Matrix b)
	{
		Matrix c(a.n,b.m);
		for (int i = 0;i < c.n;i++){
			for (int j = 0;j < c.m;j++){
				int temp = 0;
				for (int k = 0;k < a.m;k++){
					temp = (temp + a.d[i][k] * b.d[k][j])%MOD;
				}
				c.d[i][j] = temp;
			}
		}
		return c;
	}	
};
int solve(int n)
{
	Matrix a(1,3);
	Matrix b(3,3);
	int aa[3] = {1,0,0};
	int bb[3*3]={
		2,0,2,
		0,2,2,
		1,1,2
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
	int T,n;
	cin>>T;
	while (T--){
		cin>>n;
		cout<<solve(n)<<endl;
	}


	return 0;
}
