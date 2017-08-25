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
	int left;
	int right;
	int value;
};
class Tree
{
private:
	Node node[4*maxn];
public:
	int a[maxn];
	void clear(){CL(a),CL(node);};
	void build(int left,int right,int pos=1)
	{
		node[pos].left = left;
		node[pos].right = right;
		if (left == right){
			node[pos].value = a[left];
			return ;
		}
		build(left,(left+right)/2,2*pos);
		build((left+right)/2+1,right,2*pos+1);
		node[pos].value = max(node[2*pos].value,node[2*pos+1].value);
	}
	int query(int height,int pos = 1)
	{
		if (height > node[pos].value){
			return INF;
		}
		if (node[pos].left == node[pos].right && height <= node[pos].value){
			return node[pos].left;
		}
		int ret;
		if (node[2*pos].value >= height)
			ret = query(height,2*pos);
		else 
			ret = query(height,2*pos+1);
		return ret;
	}
	int update(int index,int pos = 1)
	{
		if (index > node[pos].right || index < node[pos].left){
			return node[pos].value;
		}
		if (index == node[pos].left && index == node[pos].right){
			++a[index];
			return node[pos].value =a[index];
		}
		int l = update(index,2*pos);
		int r = update(index,2*pos+1);
		
		return node[pos].value = max(l,r);
	}
	void show(int n)
	{
		for (int i = 1;i <= n;i++){
			printf("%d\n",a[i]);
		}
	}

};
int b[maxn];
Tree T;
int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m) != EOF){
		T.clear();
		for (int i = 1;i <= n;i++){
			scanf("%d",&T.a[i]);
		}
		T.build(1,n);
		for (int i = 1;i <= m;i++){
			scanf("%d",&b[i]);
		}
		for (int i = 1;i <= m;i++){
			int t = T.query(b[i]);
			if (t <= 1 || t == INF)
				continue;
			T.update(t-1);
		}
		T.show(n);	
	}
	return 0;
}
