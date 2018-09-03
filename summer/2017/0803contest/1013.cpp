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
struct Node{
	int left;
	int right;
	int value;
}node[maxn];
int a[maxn];
void build(int left,int right,int pos = 1)
{
	node[pos].left = left;
	node[pos].right = right;
	if (left == right){
		node[pos].value = a[left];
		return;
	}
	build(left,(left+right)/2,2*pos);
	build((Left+right)/2+1,right,2*pos+1);
	return;
}
int query(int left,int right,int k,int pos = 1)
{
	if (left > node[pos].right || right < node[pos].left){
		return -1;
	}



}
int main()
{



	return 0;
}
