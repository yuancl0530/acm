/*********************************
Date: Tue Apr 24 09:29:51 CST 2018
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
#define ll long long
#define ull unsigned long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
struct Node
{
	int p,u;
}a[maxn],b[maxn];
int next[maxn];
bool cmp(Node *a,int x, Node *b,int y)
{
	if (a[x].u != b[y].u) return false;
	if (y==1){
		return a[x].p-a[x-1].p>=b[y].p;
	}
	return (a[x].p-a[x-1].p) == (b[y].p-b[y-1].p);
}
void getnext(Node *a, int n)
{
	int k = 0;
	next[1] = 0;
	for (int i=2;i<=n;++i){
		while (k >0 && !cmp(a,i,a,k+1)){
			k = next[k];
		}
		if (cmp(a,i,a,k+1)){
			++k;
		}
		next [i] = k;
	}
}
int solve(int L1,int n1,int L2,int n2)
{
	int ans  = 0;
	a[0].p = b[0].p = 0;
	getnext(b,n2);
	int k = 0;
	for (int i=1;i<=n1;++i){
		while (k > 0 && !cmp(a,i,b,k+1)){
			k = next[k];
		}
		if (cmp(a,i,b,k+1)){
			++k;
		}
		if (k==n2){
			if (b[k].p == L2){
				++ans;
			}
			else if (i == n1){
				if (L1-a[i].p >= L2-b[k].p){
					++ans;
				}
			}
			else if (a[i+1].p-a[i].p>=L2+1-b[k].p){
				++ans;
			}
			k = next[k];
		}
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	int kase = 0;
	int L1,L2,n1,n2;
	int t1,t2,u,v;

	while (T--){
		t1=t2=0;
		scanf("%d%d",&L1,&n1);
		for (int i=1;i <= n1;++i){
			scanf("%d%d",&u,&v);
			if (v){
				a[++t1].p = u;
				a[t1].u = v;
			}
		}
		scanf("%d%d",&L2,&n2);
		for (int i=1;i <= n2;++i){
			scanf("%d%d",&u,&v);
			if (v){
				b[++t2].p = u;
				b[t2].u = v;
			}
		}
		int ans = 0;
		if (L1<L2){
			ans =0;
		}
		else if (t2){
			ans = solve(L1,t1,L2,t2);
		}
		else{
			if (!t1){
				ans = L1 - L2 + 1;
			}
			else {
				int t=0;
				for (int i=1;i<=t1;++i){
	//				cout<<i<<" "<<ans<<endl;
					int tmp = a[i].p-t-1;
					if (tmp>=L2){
						ans += tmp-L2+1;
					}
					t = a[i].p;
				}
				if (a[t1].p!=L1){
					int tmp = L1-a[t1].p;
	//				cout<<tmp<<endl;
					if (tmp>=L2)
						ans += tmp-L2+1;
				}
			}
		}
		//printf("%d %d\n",L1,t1);
		printf("CASE #%d: %d\n",++kase,ans);
	}
	return 0;
}
