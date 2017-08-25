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
int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
struct Matrix
{
	int n,m;
	int d[30][30];
	Matrix(int a = 0,int b = 0)
	{
		n = a;
		m = b;
		CL(d);
	}
	void copy(int *t)
	{
		for (int i = 0;i < n;i++){
			for (int j = 0;j < m;j++){
				d[i][j] = *t;
			}
		}
	}
	friend Matrix operator *(Matrix a,Matrix b)
	{
		Matrix c(a.n,b.m);
		for (int i = 0;i < a.n;i++){
			for (int j = 0;j < b.m;j++){
				int temp = 0;
				for (int k = 0;k < a.m;k++){
					temp = (temp + a.d[i][k]*b.d[k][j]) % MOD;
				}
				c.d[i][j] = temp;
			}
		}
		return c;
	}
	friend Matrix operator +(Matrix a,Matrix b)
	{
		Matrix c(a.n,a.m);
		for (int i = 0;i < c.n;i++){
			for (int j = 0;j < c.m;j++){
				c.d[i][j] = (a.d[i][j] + b.d[i][j])%MOD;
			}
		}
		return c;
	}
	void show()
	{
		for (int i = 0;i < n;i++){
			for (int j = 0;j < m;j++){
				printf("%d ",d[i][j]);
			}
			printf("\n");
		}
	}
};
Matrix E,A;
Matrix Pow(Matrix a,int k)
{
	if (k == 1)	return a;
	if (k == 0) return E;
	if (k&1)
		return a*Pow(a*a,k>>1);
	return Pow(a*a,k>>1);
}
Matrix solve(Matrix a,int k)
{
	if (k == 1) return a;
	if (k&1) return Pow(a,k) + (E+Pow(a,k>>1))*solve(a,k>>1);
	return (E+Pow(a,k>>1)) * solve(a,k>>1);
}
int main()
{
	int n,k,m;
	while (scanf("%d%d%d",&n,&k,&m) != EOF){
		E.n = E.m = A.n = A.m = n;
		for (int i = 0;i < n;i++){
			for (int j = 0;j < n;j++){
				scanf("%d",&A.d[i][j]);
				if (i == j)
					E.d[i][j] = 1;
			}
		}
		MOD = m;
		Matrix ans = solve(A,k);
		ans.show();
	}


	return 0;
}
