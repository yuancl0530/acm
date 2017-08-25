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
struct Node
{
	int left;
	int right;
	LL value;
	LL lazy;
}node[4*maxn];
int a[maxn];
void build(int left,int right,int pos = 1)
{
	node[pos].left = left;
	node[pos].right = right;
	node[pos].lazy = 0;
	if (left == right){node[pos].value = a[left]; return;}
	build(left,(left+right)>>1,2*pos);
	build(((left+right)>>1)+1,right,2*pos+1);
	node[pos].value = node[2*pos].value + node[2*pos+1].value;
	return ;
}
LL query(int left,int right,int lazy = 0,int pos = 1)
{
	if (left > node[pos].right || right < node[pos].left) {
		return 0;
	}
	if (left <= node[pos].left && node[pos].right <= right) {
		return node[pos].value + (node[pos].right - node[pos].left + 1) * (node[pos].lazy + lazy);
	}
	lazy += node[pos].lazy;
	LL l = query(left,right,lazy,2*pos);
	LL r = query(left,right,lazy,2*pos+1);
	return l + r;
}
LL update(int left,int right,int value,int pos = 1)
{
	if (left > node[pos].right || right < node[pos].left){ 
		return node[pos].value + node[pos].lazy * (node[pos].right - node[pos].left + 1);
	}

	if (left <= node[pos].left && node[pos].right <= right){
		node[pos].lazy += value;
		return node[pos].value + (LL)(node[pos].right - node[pos].left + 1) * node[pos].lazy;
	}
	if (node[pos].lazy){
		node[2*pos].lazy += node[pos].lazy;
		node[2*pos+1].lazy += node[pos].lazy;
		node[pos].lazy = 0;
	}
	LL l = update(left,right,value,2*pos);
	LL r = update(left,right,value,2*pos+1);
	return node[pos].value = l + r;
}
char s[10];
int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m) != EOF){
		CL(a);
		CL(node);
		for (int i = 1;i <= n;i++) {
			scanf("%d",&a[i]);
		}
		build(1,n);
		while (m--){
			scanf("%s",s);
			if (s[0] == 'Q'){
				int x,y;
				scanf("%d%d",&x,&y);
				printf("%lld\n",query(x,y));
			}
			else{
				int x,y,z;
				scanf("%d%d%d",&x,&y,&z);
				update(x,y,z);
			}
		} 
	}
	return 0;
}
