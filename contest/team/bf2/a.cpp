/*********************************
Date: Thu May  3 08:54:00 CST 2018
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
#define uLL unsigned long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
struct Node
{
	int left;
	int right;
	LL s;
	LL lazy;
}node[4*maxn];
void build(int left,int right,int pos = 1)
{
	node[pos].left = left;
	node[pos].right = right;
	node[pos].s = 0;
	node[pos].lazy = 0;
	if (left == right){
		return ;
	}
	build(left,(left+right)/2,2*pos);
	build((left+right)/2+1,right,2*pos+1);
}
void push(int pos)
{
	node[2*pos].lazy += node[pos].lazy;
	node[2*pos+1].lazy += node[pos].lazy;	
	node[pos].s += node[pos].lazy*(node[pos].right-node[pos].left+1);
	node[pos].lazy = 0;
}
LL update(int l,int r,LL v,int pos=1)
{
	if (l>node[pos].right || r<node[pos].left){
		return node[pos].s+node[pos].lazy*(node[pos].right-node[pos].left+1);
	}
	if (l<=node[pos].left && node[pos].right <=r){
		node[pos].lazy += v;
		return node[pos].s + node[pos].lazy*(node[pos].right-node[pos].left+1);
	}
	push(pos);
	LL l1 = update(l,r,v,2*pos);
	LL r1 = update(l,r,v,2*pos+1);
	return node[pos].s = l1+r1;
}

LL query(int l, int r,int pos=1)
{
	if (l>node[pos].right || r<node[pos].left){
		return 0;
	}
	if (l<=node[pos].left && node[pos].right<=r){
		return node[pos].s+node[pos].lazy*(node[pos].right-node[pos].left+1);
	}
	push(pos);
	LL l1 = query(l,r,2*pos);
	LL r1 = query(l,r,2*pos+1);
	return l1+r1;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		int m,n;
		scanf("%d",&n);
		build(1,n);
		scanf("%d",&m);
		int x,y,w,h;
		for (int i=0;i<m;++i){
			scanf("%d%d%d%d",&x,&y,&w,&h);
			update(x+1,x+w,h);
		}
		LL tot = query(1,n);
		int ans=0;
		LL t;
		for (int i=1;i<=n;++i){
			LL s = query(1,i);
			if (s>=tot-s){
				ans = i;
				t =s;
				break;
			}
		}
		int l = ans;
		int r = n+1;
		while(l+1<r){
			int mid = (l+r)/2;
			if (query(1,mid)<=t){
				l = mid;
			}
			else{
				r = mid;
			}
		}
		printf("%d\n",l);
	}
	return 0;
}
