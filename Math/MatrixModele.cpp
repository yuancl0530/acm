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
int main()
{



	return 0;
}
