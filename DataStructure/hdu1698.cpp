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
const int maxn = 1e5 + 10;
struct Node
{
	int left;
	int right;
	int value;
	int lazy;
};
class Tree
{
public:
	Node node[4*maxn];
	void clear()
	{
		CL(node);
		return ;
	}
	void build(int left,int right,int pos = 1)
	{
		node[pos].left = left;
		node[pos].right = right;
		node[pos].lazy = 0;
		if (left == right){
			node[pos].value  =1;
			return ;
		}
		build(left,(left+right)/2,2*pos);
		build((left+right)/2+1,right,2*pos+1);
		node[pos].value = node[2*pos].value + node[2*pos+1].value;
		return ;
	}
	int query(int left,int right,int pos = 1)
	{
		if (right < node[pos].left || left > node[pos].right){
			return 0;
		}
		if (left <= node[pos].left && node[pos].right <= right){
			return node[pos].value;
		}
		int l = query(left,right,2*pos);
		int r = query(left,right,2*pos+1);
		return l + r;
	}
	int update(int left,int right,int value,int pos = 1)
	{
		if (left > node[pos].right || right < node[pos].left){
			if (node[pos].lazy)
				return node[pos].value = (node[pos].right-node[pos].left+1)*node[pos].lazy;
			return node[pos].value;
		}

		if (left <= node[pos].left && node[pos].right <= right){
			node[pos].lazy = value;
			return node[pos].value = (node[pos].right-node[pos].left+1)*value;
		}
		if (node[pos].lazy)node[2*pos].lazy = node[2*pos+1].lazy = node[pos].lazy;
		node[pos].lazy = 0;
		int l = update(left,right,value,2*pos);
		int r = update(left,right,value,2*pos+1);
		return node[pos].value = l + r;
	}
	
};
Tree T;
int main()
{
	int t;
	scanf("%d",&t);
	int n,m;
	int k = 0;
	while (t--){
		scanf("%d",&n);
		T.clear();
		T.build(1,n);
		int x,y,z;
		scanf("%d",&m);
		for (int i = 0;i < m;i++){
			scanf("%d%d%d",&x,&y,&z);
			T.update(x,y,z);
		}
		printf("Case %d: The total value of the hook is %d.\n",++k,T.query(1,n));
	}
	return 0;
}
