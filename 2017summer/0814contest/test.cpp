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
struct Node
{
	int v;
	friend Node operator * (Node a,Node b){
		Node c;
		c.v= 1;
		if (a.v == 1 && b.v == 1)
			c.v = 0;
		return c;
	}
}a[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0;i < n;i++){
		scanf("%d",&a[i].v);
		cout<<a[i].v<<" ";
	}
	Node ans = a[0];
	cout <<endl<< a[0].v <<" ";
	for (int i = 1;i < n;i++){
		ans = ans * a[i];
		cout << ans.v<<" ";
	}
	cout<<endl;
	return 0;
}
