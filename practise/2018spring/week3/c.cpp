/*********************************
Date: Mon Mar 19 13:52:30 CST 2018
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
const int maxn = 2000;
int a[maxn];
int pos[maxn];
int n;
vector<int> V[maxn];
stack<int> S;
void init()
{
	CL(a);
	CL(pos);
	while (!S.empty()) S.pop();
	for (int i=0;i<=1010;++i)
		V[i].clear();
}
int main()
{
	int t;
	while (scanf("%d",&n)!=EOF){
		init();
		for (int i=1;i<=n;++i){
			scanf("%d",&t);
			pos[t] = i;
		}
		for (int i=0;i<n;++i){
			scanf("%d",&a[i]);
		}
		S.push(a[0]);
		for (int i=1;i<n;++i){
			t = S.top();
			while (t!=a[0] && pos[t]+1 >= pos[a[i]]) {
				S.pop();
				t = S.top();
			}
			V[t].push_back(a[i]);
			S.push(a[i]);
		}
		for (int i=1;i<=n;++i){
			printf("%d:",i);
			for (int j=0;j<V[i].size();++j)
				printf(" %d",V[i][j]);
			printf("\n");
		}
	}
	return 0;
}
