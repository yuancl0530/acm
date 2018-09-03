/*********************************
Date: Sat Aug 19 12:53:49 CST 2017
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
int a[maxn];
int f(int m,int n)
{
	int cnt = 0;
	while (m){
		a[++cnt] = m%n;
		m/=n;
	}
	for (int i = 1;i <= cnt;i++){
		if (a[i] != a[cnt+1-i])
			return 1;
	}
	return n;
}
#define N 10
vector<int>V[40];
int main()
{
		int R,L,l,r;
		int t = N;
		while(cin>>L>>R>>l>>r){

	int cnt = 0;
	for (int i = L;i<=R;i++){
		for (int j = l;j<=r;j++){
			cnt+=f(i,j);
		}
	}
	cout<<cnt<<endl;
	}
	return 0;
}
