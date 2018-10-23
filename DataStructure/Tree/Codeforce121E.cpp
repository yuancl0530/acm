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
const int maxn = 1e6+10;
int a[maxn];
int sum[maxn];
int n;
int lowbit(int x){return x&-x;}
int Sum(int pos)
{
	int ret = 0;
	while (pos > 0){
		ret += sum[pos];
		pos -= lowbit(pos);
	}
	return ret;
}
void update(int pos,int d)
{
	while (pos <= n){
		sum[pos] += d;
		pos += lowbit(pos);
	}

}
int luck[10100];
void dfs(int n)
{
	if (n > 10000)
		return ;
	luck[n] = 1;
	dfs(10*n+4);
	dfs(10*n+7);
}
int main()
{
	int m,l,r,d;
	char s[10];
	CL(luck);
	dfs(0);
	for (int i = 0;i < 10000;i++)
		if (luck[i])
			printf("%d\n",i);
	while (scanf("%d%d",&n,&m) != EOF){
		CL(sum);
		for (int i = 1;i <= n;i++){
			scanf("%d",&a[i]);
			if (luck[a[i]])
				update(i,1);
		}
		for (int i = 0;i < m;i++){
			scanf("%s",s);
			if (!strcmp(s,"count")){
				scanf("%d%d",&l,&r);
				printf("%d\n",Sum(r) - Sum(l-1));
			}else{
				scanf("%d%d%d",&l,&r,&d);
				for (int j = l;j <= r;j++){
					int temp = a[j];
					a[j] += d;
					if (luck[temp] && !luck[a[j]]){
						update(j,-1);
					}else if (!luck[temp] && luck[a[j]]){
						update(j,1);
					}
				}
			}
		}
	}
	return 0;
}
