/*********************************
Date: Fri Sep 29 20:01:58 CST 2017
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
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 2e6 + 100;
struct TT
{
	int x;
	int y;
	int i;
}b[maxn],ans[maxn];
struct Node
{
	int left;
	int right;
	int value;
}node[4*maxn];
int k;
bool cmp1(TT a,TT b)
{
	return a.x<b.x;
}
bool cmp2(TT a ,TT b)
{
	if (a.i != b.i)
		return a.i<b.i;
	return a.x<b.x;
}
int a[maxn];
void build(int left,int right,int pos)
{
	node[pos].left=left;
	node[pos].right=right;
	node[pos].value=0;
	if (left==right)
		return;
	build(left,(left+right)/2,2*pos);
	build((left+right)/2+1,right,2*pos+1);
}
void update(int left,int right,int pos=1)
{
	if (left >node[pos].right || right <node[pos].left)
		return ;
	if (left <=node[pos].left && node[pos].right <=right){
		node[pos].value++;
		if (node[pos].value>k)
			node[pos].value=k;
		return;
	}
	if (node[pos].left==node[pos].right) return;
	if (node[pos].value){
		node[2*pos].value+=node[pos].value;
		node[2*pos+1].value+=node[pos].value;
		node[pos].value=0;
	}
	update(left,right,2*pos);
	update(left,right,2*pos+1);
}
int cnt_ans=0;
int c[maxn];
void query(int pos=1,int lazy=0)
{
	if (node[pos].left == node[pos].right){
		c[node[pos].left]=node[pos].value;
		return ;
	}
	node[2*pos].value+=node[pos].value;
	node[2*pos+1].value+=node[pos].value;
	query(2*pos);
	query(2*pos+1);
}
void Init()
{
	cnt_ans=0;
}
int main()
{
	int n;
	while (scanf("%d%d",&n,&k) != EOF){
		Init();
		for (int i=1;i<=n;i++){
			scanf("%d",&b[2*i-1].x);
			scanf("%d",&b[2*i].x);
			b[2*i-1].i=b[2*i].i=i;
		}
		sort(b+1,b+1+2*n,cmp1);
		b[1].y=1;
		int cnt=1;
		a[1]=b[1].x;
		for (int i=2;i<=2*n;++i){
			if (b[i].x != b[i-1].x){
				b[i].y=++cnt;
				a[cnt]=b[i].x;
			}
			else
				b[i].y=cnt;
			cout<<b[i].x<<" "<<b[i].y<<endl;
		}
		sort(b+1,b+1+2*n,cmp2);
		build(1,cnt,1);
		for (int i=1;i<=n;i++){
			update(b[2*i-1].y,b[2*i].y);
			cout<<"*"<<b[2*i-1].y<<" "<<b[2*i].y<<endl;
		}
		query();
		for (int i=1;i<100;++i){
			if (node[i].left){
				cout<<node[i].left<<" "<<node[i].right<<" "<<node[i].value<<endl;
			}
		}
		for (int i=1;i<=cnt;++i)
			cout<<c[i]<<" ";
		cout<<endl;
		int l=0;
		for (int i=1;i<=cnt;++i){
			if (c[i]>=k && !l){
				l=i;
			}
			else{
				if (l && c[i]<k || c[i]!=c[i-1]+1){
					ans[++cnt_ans].x=a[l];
					ans[cnt_ans].y=a[i-1];
					l=0;
				}
			}
		}
		cout<<cnt_ans<<endl;
		for (int i=1;i<=cnt_ans;++i)
			printf("%d %d\n",ans[i].x,ans[i].y);
	}
	return 0;
}
