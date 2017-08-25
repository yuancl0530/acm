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
	int value;
}node[4*maxn];
int h,w,n;
int a[maxn];
void build(int left,int right,int pos = 1)
{
	node[pos].left = left;
	node[pos].right = right;
	node[pos].value = w;
	if (left == right) return;
	build(left,(left+right)/2,2*pos);
	build((left+right)/2+1,right,2*pos+1);
}

int query(int value,int pos = 1)
{
	if (node[pos].left == node[pos].right)
		return node[pos].left;
	if (node[2*pos].value >= value){
		return query(value,2*pos);
	}
	else if (node[2*pos+1].value >= value){
		return query(value,2*pos+1);
	}
	else return -1;
}

int update(int value,int index,int pos = 1)
{
	if (index < node[pos].left || index > node[pos].right){
		return node[pos].value;
	}
	if (node[pos].left == node[pos].right)
		return node[pos].value -= value; 
	int l = update(value,index,2*pos);
	int r = update(value,index,2*pos+1);
	return node[pos].value = max(l,r);
}
int main()
{
	while (scanf("%d%d%d",&h,&w,&n) != EOF){
		int t;
		h = min(h,200010);
		build(1,h);
		for (int i = 0;i < n;i++){
			scanf("%d",&t);
			int ans = query(t);
			printf("%d\n",ans);
			if (ans != -1){
				update(t,ans);
			}
		}
	}
	return 0;
}
