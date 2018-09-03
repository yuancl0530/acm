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
const int maxn = 5e5 + 100;
struct Node
{
	int left,right;
	int cl,cm,cr;
	int lazy;
}node[4*maxn];
void build(int left,int right,int pos = 1)
{
	node[pos].left = left;
	node[pos].right = right;
	node[pos].lazy = -1;
	node[pos].cl = node[pos].cr = node[pos].cm = right - left + 1;
	if (left == right) 
		return;
	build(left,(left+right)/2,2*pos);
	build((left+right)/2+1,right,2*pos+1);
	return;
}
void pushLazy(int pos)
{
	if (node[pos].lazy != -1){
		node[2*pos].lazy = node[2*pos+1].lazy = node[pos].lazy;
		node[2*pos].cl = node[2*pos].cr = node[2*pos].cm = (node[2*pos].right - node[2*pos].left + 1) * node[2*pos].lazy;
		node[2*pos+1].cl = node[2*pos+1].cr = node[2*pos+1].cm = (node[2*pos+1].right - node[2*pos+1].left + 1) * node[2*pos].lazy;
		node[pos].lazy = -1;

	}
	
}
void update(int left,int right,int value,int pos = 1)
{
	if (left > node[pos].right || right < node[pos].left){
		return ;
	}
	if (left <= node[pos].left && node[pos].right <= right){
		if (value == 0)
			node[pos].lazy = 0;
		else
			node[pos].lazy = 1;
		node[pos].cl = node[pos].cm = node[pos].cr = (node[pos].right  - node[pos].left + 1) * node[pos].lazy;
		return ;
	}
	pushLazy(pos);
	update(left,right,value,2*pos);
	update(left,right,value,2*pos+1);
	if (node[2*pos].cl == node[2*pos].right - node[2*pos].left + 1)
		node[pos].cl = node[2*pos].cl + node[2*pos+1].cl;
	else
		node[pos].cl = node[2*pos].cl;
		
	if (node[2*pos+1].cr == node[2*pos+1].right - node[2*pos+1].left + 1)
		node[pos].cr = node[2*pos+1].cr + node[2*pos].cr;
	else
		node[pos].cr = node[2*pos+1].cr;
	node[pos].cm = max(node[2*pos].cr+node[2*pos+1].cl ,max(node[2*pos].cm,node[2*pos+1].cm));
	return;
}

int query(int value,int pos = 1)
{
	if (node[pos].cm < value)
		return 0;
	if (node[pos].cl >= value){
		return node[pos].left;
	}
	pushLazy(pos);
	if (node[2*pos].cm >= value)
		return query(value,2*pos);
	else if (node[2*pos].cr + node[2*pos+1].cl >= value)
		return node[2*pos].right - node[2*pos].cr + 1;
	else 
		return query(value,2*pos+1);

}

void print()
{
	for (int i = 1;i < 100;i++){
		if (node[i].left){
			Node &t = node[i];
			printf("[%2d,%2d] cl=%d cm =%d cr = %d lz=%d\n",t.left,t.right,t.cl,t.cm,t.cr,t.lazy);
		}
	}
}

int main()
{
	int n,m,s,x,y;
	while (scanf("%d%d",&n,&m) != EOF){
		CL(node);
		build(1,n);
		while (m--){
			scanf("%d",&s);
			if (s == 1){
				scanf("%d",&x);
				y = query(x);
				if (y)
					update(y,y+x-1,0);
				printf("%d\n",y);
			}
			else{
				scanf("%d%d",&x,&y);
				int r = min(n,x+y-1);
				update(x,r,1);
			}
		}
	}
	return 0;
}
