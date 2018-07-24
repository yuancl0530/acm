/*********************************
Date: Sun Mar 18 15:41:19 CST 2018
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
#include <set>
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define LL long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
int pre[maxn],Next[maxn];
void init(int n)
{
	pre[0]=0;
	for (int i=1;i<=n+1;++i)
		pre[i] = i-1;
	Next[n]=0;
	for (int i=0;i<=n;++i)
		Next[i]=i+1;
	Next[n+1]=0;
}
void Move(int x,int y,int op=0)//0 left 1 right
{
	Next[pre[y]] = Next[y];
	pre[Next[y]] = pre[y];
	if (op==0){
		Next[pre[x]] = y;
		pre[y] = pre[x];
		pre[x] = y;
		Next[y] = x;
	}
	else {
		pre[Next[x]] = y;
		Next[y] = Next[x];
		pre[y] = x;
		Next[x] = y;
	}
}
int main()
{
	int T;
	int n,m;
	int kase=0;
	while (scanf("%d%d",&n,&m)!= EOF){
		init(n);
		int op,x,y;
		bool inv=0;
		for (int i=0;i<m;++i){
			#ifdef TEST
				cout<<i+1<<endl;
			#endif
			scanf("%d",&op);;
			if (op==4) inv ^= 1;
			else {
				scanf("%d%d",&y,&x);
				if (op==1){
					if (!inv){
						if (pre[x] != y) Move(x,y,0);
					}
					else {
						if (Next[x] != y)Move(x,y,1);
					}
				}
				else if (op==2) {
					if (!inv) {
						if (Next[x] != y)Move(x,y,1);
					}
					else{
						if (pre[x] != y)Move(x,y,0);
					}
				}
				else {
					if (Next[x] == y){
						Next[pre[x]] = y;
						pre[Next[y]] = x;
						Next[x] = Next[y];
						pre[y] = pre[x];
						Next[y] = x;
						pre[x] = y;
					}
					else{
						int tmp = Next[x];
						Move(y,x,0);
						Move(tmp,y,0);
					}
				}
			}
		}
		LL ans = 0;
		if (!inv){
			for (int i=Next[0],cnt=1;Next[i];i=Next[i],++cnt){
				if (cnt&1)
					ans += i;
			}
		}
		else{
			for (int i=pre[n+1],cnt=1;i;i=pre[i],++cnt){
				if (cnt &1) ans += i;
			}
		}
		printf("Case %d: %lld\n",++kase,ans);
	}
	return 0;
}
