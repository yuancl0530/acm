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
const int maxn = 1e4 + 100;
int a[maxn],b[maxn];
int lch[maxn],rch[maxn];
int build(int l1,int r1,int l2,int r2) 
//a[l1]-a[r1]表示子树先序遍历的范围  b[l2]-b[r2]表示子树中序遍历的范围 
{
	if (l1>r1) return 0;
	int root = a[l1];//根节点
	int t = l2;
	while (b[t]!=root) ++t;
	int cnt = t-l2;//左子树节点个数
	lch[root]=build(l1+1,l1+cnt,  l2,t-1);
	rch[root]=build(l1+cnt+1,r1, t+1,r2);
	return root ;
}
void postOrder(int u)
{
	if (lch[u]) postOrder(lch[u]);
	if (rch[u]) postOrder(rch[u]);
	printf("%d ",u);
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for (int i=1;i<=n;++i){
		scanf("%d",&b[i]);
	}
	int root = build(1,n,1,n);
	postOrder(root);
	printf("\n");
	return 0;
}
