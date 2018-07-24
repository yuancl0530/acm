#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <list>
#include <set>
using namespace std;
#define CL(a) memset(a,0,sizeof(a));
#define INF 0x7fffffff
const int maxn = 200000 + 10;
struct node
{
	int left;
	int right;
	int value;
}Node[4*maxn];
int a[maxn];
void Buildtree(int pos,int left,int right)
{
	Node[pos].left = left;
	Node[pos].right = right;
	if (left == right){
		Node[pos].value = a[left];
	}else {
		Buildtree(2*pos,left,(left+right)/2);
		Buildtree(2*pos+1,(left+right)/2+1,right);
		Node[pos].value = max(Node[2*pos].value,Node[2*pos+1].value);
	}

}
int query(int pos,int left,int right)
{
	if (right < Node[pos].left || left > Node[pos].right)
		return -1;
	if (left <= Node[pos].left && Node[pos].right <= right)
		return Node[pos].value;
	int l,r;
	l = query(2*pos,left,right);
	r = query(2*pos+1,left,right);
	return max(l,r);
}
int update(int root,int pos,int val)
{
	if (pos == Node[root].left && pos == Node[root].right)
		return Node[root].value = a[pos] =  val;
	if (Node[root].left > pos || Node[root].right < pos)
		return Node[root].value;
	int a = update(2*root,pos,val);
	int b = update(2*root+1,pos,val);
	return Node[root].value = max(a,b);
}
int main()
{
	int n,m;
	char c;
	int x,y;
	while (scanf("%d%d",&n,&m) != EOF){
		CL(a);
		CL(Node);
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		Buildtree(1,1,n);
		for (int i = 0;i < m;i++){
			getchar();
			scanf("%c%d%d",&c,&x,&y);
			if (c == 'Q')
				printf("%d\n",query(1,x,y));
			else
				update(1,x,y);
		}
	}
	return 0;
}
