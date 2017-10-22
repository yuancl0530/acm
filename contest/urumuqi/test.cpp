/*********************************
Date: Sat Sep  9 13:04:05 CST 2017
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
const int maxn = 1e8 + 100;
LL f[maxn];
int main()
{
	int cnt=0;
	for (LL i=1;i<=1e8;++i){
		f[cnt++]=i*i;
	}
	for (int i=0;i<cnt;i++){
		LL t1,t2;
		LL a=f[i];
		LL t;
		if (a&1){
			t2=(a+1)>>1;
			t1=a;
			t=a;
		}
		else{
			t=2*a;
			t1=a;
			t2=2*t1+1;
		}
		LL tt1=sqrt(t1);
		LL tt2=sqrt(t2);
		if (tt1*tt1==t1&&tt2*tt2==t2)
				cout<<t<<',';
		
	}
	return 0;
}
