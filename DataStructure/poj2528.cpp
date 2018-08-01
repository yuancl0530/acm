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
void build(int left,int right,int pos = 1)
{
	node[pos].left = left;
	node[pos].right = right;
	node[pos].value = -1;
	if (left == right) return;
	build(left,(left+right)/2,2*pos);
	build((left+right)/2+1,right,2*pos+1);
}
void update(int left,int right,int value,int pos = 1)
{
	if (left > node[pos].right || right < node[pos].left){
		return;
	}	
	if (left <= node[pos].left && node[pos].right <= right){
		node[pos].value = value;
		return;
	}
	if (node[pos].value){
		node[2*pos].value = node[2*pos+1].value = node[pos].value;
		node[pos].value = 0;
	}
	update(left,right,value,2*pos);
	update(left,right,value,2*pos+1);
}
set<int>S;
void query(int pos = 1)
{
	if (node[pos].value){
		if (node[pos].value != -1)
			S.insert(node[pos].value);
		return;
	}
	query(2*pos);
	query(2*pos+1);
	return ;
}

struct Post
{
	int pos;
	int value;
}post[maxn];
bool cmp(Post a,Post b)
{
	return a.value < b.value;
}
bool cmp2(Post a,Post b)
{
	if (a.pos != b.pos){
		return a.pos < b.pos;
	}
	return a.value < b.value;
}

int main()
{
	int t;
	int n,m,l,r;
	scanf("%d",&t);
	while (t--){
		S.clear();
		CL(node);
		CL(post);
		scanf("%d",&n);
		for (int i = 1;i <= n;i++){
			scanf("%d%d",&post[2*i-1].value,&post[2*i].value);
			post[2*i-1].pos = i;
			post[2*i].pos = i;
		}
		int sum = 1;
		sort(post+1,post+2*n+1,cmp);
		post[1].value = sum;
		int last = post[1].value;
		for (int i = 2;i <= 2*n;i++){
			if (post[i].value == last){
				last = post[i].value;
				post[i].value = sum;
			}
			else{
				last = post[i].value;
				post[i].value = ++sum;
			}
		}
		build(1,sum);
		sort(post+1,post+2*n+1,cmp2);

		for (int i = 1;i <= n;i++){
			update(post[2*i-1].value,post[2*i].value,i);
		}
		query();
		int ans = S.size();
		printf("%d\n",ans);
	}
	return 0;
}
