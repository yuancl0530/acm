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
const int MOD = 10000;
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
				for (int k = 0;k < a.m;k++){
					temp = (temp + a.d[i][k] * b.d[k][j]) % MOD;
				}
				c.d[i][j] = temp;
			}
		}
		return c;
	}
};
int solve(int n)
{
	if (n==0)return 0;
	int aa[2] = {0,1};
	int bb[2*2] = {1,1,1,0};
	Matrix a(1,2);
	Matrix b(2,2);
	a.copy(aa);
	b.copy(bb);
	while (n > 1){
		if (n&1){
			a = a * b;
		}
		b = b*b;
		n>>=1;
	}
	a = a*b;
	return a.d[0][0];
}
int main()
{
	int n;
	while (scanf("%d",&n) != EOF && n!=-1){
		printf("%d\n",solve(n));
	}
	return 0;
}
