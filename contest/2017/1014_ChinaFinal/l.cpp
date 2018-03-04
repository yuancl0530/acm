/*********************************
Date: Sat Oct 14 13:58:14 CST 2017
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
#define INFLL 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
int bit[6];
int cnt[10000];
int add(int &a,int &b,int s)
{
	if (s==0){
		++a;
		++b;
	}
	else if (s==1)
		a+=3;
	else {
		b+=3;
	}
}
void Init()
{
	for (int i=0;i<729;++i){
		int t=i;
		int a=0,b=0,c=0,d=0;
		for (int j=0;j<6;++j){
			bit[j]=t%3;
			t/=3;
		}
		add(a,b,bit[0]);
		add(a,c,bit[1]);
		add(a,d,bit[2]);
		add(b,c,bit[3]);
		add(b,d,bit[4]);
		add(c,d,bit[5]);
		cnt[a*1000+b*100+c*10+d]++;
	}
}
int main()
{
	Init();
	int a,b,c,d;
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;++t){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("Case #%d: ",t);
		if (a>9||b>9||c>9||d>9){
			printf("Wrong Scoreboard\n");
			continue;
		}
		else if (cnt[a*1000+b*100+c*10+d]==0){
			printf("Wrong Scoreboard\n");
			continue;
		
		}
		if (cnt[a*1000+b*100+c*10+d]==1)
			printf("Yes\n");
		else 
			printf("No\n");
	}

	return 0;
}
