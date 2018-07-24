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
const int maxn = 2e5 + 100;
struct Node
{
	int pos;
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
	Tree()
	{
		CL(node);
	}
	void clear(){CL(node),CL(node);}
	void build(int pos,int left,int right)
	{
		node[pos].left = left;
		node[pos].right = right;
		if (left == right){
			node[pos].value = a[left];
			return ;
		}
		build(2*pos,left,(left+right)/2);
		build(2*pos+1,(left+right)/2+1,right);
		node[pos].value = max(node[2*pos].value,node[2*pos+1].value);
	}
	int query(int left,int right,int pos = 1)
	{
		if (left <= node[pos].left && node[pos].right <= right){
			return node[pos].value;
		}
		if (right < node[pos].left || left > node[pos].right){
			return -1;
		}
		int l = query(left,right,2*pos);
		int r = query(left,right,2*pos+1);
		return max(l,r);
		
	}
	int update(int index,int value,int pos = 1)
	{
		if (node[pos].left == node[pos].right && index == node[pos].left){
			return a[index] = node[pos].value = value;
		}
		if (index < node[pos].left || index > node[pos].right){
			return node[pos].value;
		}
		int l = update(index,value,2*pos);
		int r = update(index,value,2*pos+1);
		return node[pos].value = max(l,r);
	}
};
Tree T;
int main()
{
	int n,m;
	while (scanf("%d%d",&n,&m) != EOF){
		T.clear();
		for (int i = 1;i <= n;i++){
			scanf("%d",&T.a[i]);
		}
		int l,r;
		char s;
		T.build(1,1,n);
		for (int i = 0;i < m;i++){
			cin >> s;
			if (s == 'Q'){
				scanf("%d%d",&l,&r);
				printf("%d\n",T.query(l,r));
			}
			else{
				scanf("%d%d",&l,&r);
				T.update(l,r);
			}
		}
		
	}



	return 0;
}
