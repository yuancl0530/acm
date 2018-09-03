/*********************************
Date: Thu Aug 24 08:41:59 CST 2017
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
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
int a[maxn];
struct Post
{
	int pos;
	int v;
}post[maxn];
struct Node
{
	int left;
	int right;
	int lazy;
	Node ()
	{
		left=right=lazy=0;
	}
}node[maxn];
void build(int left,int right,int pos=1)
{
	node[pos].left = left;
	node[pos].right = right;
	node[pos].lazy=0;
	if (left==right) return;
	build(left,(left+right)/2,2*pos);
	build((left+right)/2+1,right,2*pos+1);
}
void update(int left,int right,int value,int pos=1)
{
	if (left > node[pos].right || right <node[pos].left)
		return ;
	if (left <= node[pos].left && node[pos].right <= right){
		node[pos].lazy = value;
		return ;
	}
	if (node[pos].lazy){
		node[2*pos].lazy=node[2*pos+1].lazy=node[pos].lazy;
		node[pos].lazy=0;
	}
	update(left,right,value,2*pos);
	update(left,right,value,2*pos+1);
}
set<int>S;
void query(int left,int right,int pos=1)
{
	if (node[pos].left >right || node[pos].right <left)
		return ;
	if (node[pos].lazy){
		S.insert(node[pos].lazy);
		return;
	}
	query(left,right,2*pos);
	query(left,right,2*pos+1);
}
bool cmp1(Post a,Post b){return a.v<b.v;}
bool cmp2(Post a,Post b)
{
	if (a.pos==b.pos)
		return a.v<b.v;
	return a.pos<b.pos;

}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		int n;
		scanf("%d",&n);
		CL(node);
		CL(post);
		S.clear();

		for (int i=0;i<n;i++){
			scanf("%d%d",&post[2*i].v,&post[2*i+1].v);
			post[2*i].pos=i+1;
			post[2*i+1].pos=i+1;
		}

		sort(post,post+2*n,cmp1);

		int last=post[0].v;
		int cnt=1;
		for (int i=0;i<2*n;i++){
			if (post[i].v!=last){
				last=post[i].v;
				post[i].v=++cnt;
			}
			else
				post[i].v=cnt;
		}
		sort(post,post+2*n,cmp2);

		build(1,cnt);
		for (int i=0;i<n;i++){
			update(post[2*i].v,post[2*i+1].v,i+1);
		}
		query(1,cnt);
		int ans=S.size();
		cout<<ans<<endl;
	}
	return 0;
}
