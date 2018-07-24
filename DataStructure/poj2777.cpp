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
const int maxn = 1e5 + 100;
struct Node
{
	int left;
	int right;
	int value;
	int lazy;
}node[4*maxn];
void build(int left,int right,int pos = 1)
{
	node[pos].left = left;
	node[pos].right = right;
	node[pos].value = 1;
	node[pos].lazy = 0;
	if (left == right){return ;}
	build(left,(left+right)>>1,2*pos);
	build(((left+right)>>1)+1,right,2*pos+1);
	return ;
}
int query(int left,int right,int pos = 1)
{
	if (left > node[pos].right || right < node[pos].left){
		
		return 0;
	}
	if (left <= node[pos].left && node[pos].right <= right){
		if (node[pos].lazy)
			return node[pos].lazy;
		return node[pos].value;
	}
	if (node[pos].lazy){
		return node[pos].lazy;
	}
	int l = query(left,right,2*pos);
	int r = query(left,right,2*pos+1);
	return l|r;

}

int update(int left,int right,int value,int pos = 1)
{
	if (left > node[pos].right || node[pos].left > right){
		if (node[pos].lazy){
			return node[pos].value = node[pos].lazy;
		}
		return node[pos].value;
	}
	if (left <= node[pos].left && node[pos].right <= right){
		return node[pos].lazy = node[pos].value = 1<<(value-1);
	}
	if (node[pos].lazy){
		node[2*pos].lazy = node[pos].lazy;
		node[2*pos+1].lazy = node[pos].lazy;
		node[pos].lazy = 0;
	}
	int l = update(left,right,value,2*pos);
	int r = update(left,right,value,2*pos+1);
	return node[pos].value = l|r;
}
int cal(int n)
{
	int ret = 0;
	while (n){
		if (n&1)
			ret++;
		n >>= 1;
	}
	return ret;
}
char s[10];
int main()
{
	int n,t,m;
	while (scanf("%d%d%d",&n,&t,&m) != EOF){
		CL(node);
		build(1,n);
		for (int i = 0;i < m;i++){
			scanf("%s",s);
			if (s[0] == 'C'){
				int x,y,z;
				scanf("%d%d%d",&x,&y,&z);
				if (x > y)
					swap(x,y);
				update(x,y,z);}
				
			else{
				int x,y;
				scanf("%d%d",&x,&y);
				if (x > y) swap(x,y);
				int t = query(x,y);
				printf("%d\n",cal(t));
			}
		
	
		}	
	}
	return 0;
}
