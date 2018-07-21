/*********************************
Date: Thu Jul 19 14:55:47 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
int cnt = 0;
int a[10][10];
void solve(int n,int v)
{
	for (int i = 1;i <= n;++i){
		for (int j = i+1;j <= n;++j){
			a[i][j] = a[j][i] = v % 3;
			v /= 3;
		}
	}
	for (int i = 1;i <= n;++i){
		int s = 0;
		for (int j = 1;j <= n;++j){
			s += a[i][j];
		}
		if (s != 2) return ;
	}
	for (int i = 1;i <= n;++i){
		for (int j = 1;j <= n;++j){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	cout << endl;
	++cnt;
}
int main()
{
	int t = 1;
	for (int i = 1;i <= 10;++i)
		t *= 3;
	for (int i = 0;i <= t;++i){
		solve(5,i);
	}
	cout << cnt << endl;
	return 0;
}
