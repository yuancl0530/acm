/*********************************
Date: Sat Aug 25 13:36:54 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x3f3f3f3f
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
struct City
{
	int id,p;
	friend bool operatorv < (City a,City b)
	{
		if (a.p != b.p) return a.p < b.p;
		return a.p < b.p;
	}
}c[maxn];
struct Node
{
	int left,right;
	int max,id;
	Node ():max(0),id(0) {}
}node[maxn];
void push_up(int pos)
{
	if (node[2*pos].max >= node[2*pos+1].max){
		node[pos].max = node[2*pos].max;
		node[pos].id = node[2*pos].id;
	}
	else{
		node[pos].max = node[2*pos+1].max;
		node[pos].id = node[2*pos+1].id;
	}
}
void build(int left,int right,int pos = 1)
{
	node[pos].left = left;
	node[pos].right = right;
	if (left == right){
		node[pos].max = c[left].p;
		node[pos].id = c[left].id;
	}
	int mid = (left+right) >> 1;
	build(left,mid,2*pos);
	build(mid+1,right,2*pos+1);
	push_up(pos);
}
void update(int x,int pos=1)
{
	if (x < node[pos].left || x > node[pos].right) return ;
	if (node[pos].left == node[pos].right){
		node[pos].max = 0;
		node[pos],id = 0;
		return ;
	}
	push_up(pos);
}
pair<int,int> query(int left,int right,int pos)
{
	
	if (right >= node[pos].left && right <= node[pos].right)
}
int main()
{

	return 0;
}
