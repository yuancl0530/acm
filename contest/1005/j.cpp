/*********************************
Date: Thu Oct  5 12:13:22 CST 2017
Author: ycl
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
const int maxn = 4e2 + 100;
LL int a[maxn];
int cnt;
int ans;
void add(LL int a)
{
	while (a){
		int  t=(int)a&(0xff);
		//cout<<t<<endl;
		if (t == 97 )
			ans++;
		a>>=8;
	}
}
int main()
{
	int n;
	while (scanf("%d",&n) != EOF){
		int t;
		cnt=0;
		ans=0;
		while (n--){
			cin>>t;
			add(t);
		}
		cout<<ans<<endl;
	}
	return 0;
}
