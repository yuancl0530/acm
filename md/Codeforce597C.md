# Codeforces 597C(树状数组 + dp)

## 题意
>给你一个长度为`n`的数组，问你长度为`k+1` 的上升子序列，一共有多少个

## 思路
>定义一个`dp[i][j]`的数组，表示前上升子序列中最后一个数字为`a[i]`并且长度为`j`的上升子序列的个数.  
$$dp[i][j]=\sum_{k=1}^{a[k]-1} dp[k][j-1]$$
#### 暴力的方法（显然会超时，用树状数组优化）
```
for (int i = 1;i <= n;i++){
	for (int j = 1;j <= min(i,k);j++){
		if (j == 1){
			dp[i][j] = 1;
		}
		for (int k = 1;k < a[i];k++)
			dp[a[i][j] += dp[k][j-1];
	}
long long ans = 0;
for (int i = 1;i <= n;i++)
	ans += dp[i][k];

```
## 代码

```
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
const int maxn = 1e5+10;
long long dp[maxn][15];//dp[x][y]表示最后一个元素为a[x]的并且长度为y的上升子序列的个数
long long a[maxn];
int n;
int lowbit(int x){return x&-x;}
long long Sum(int x,int y)
{
	long long ret = 0;
	while (x > 0){
		ret += dp[x][y];
		x -= lowbit(x);
	}
	return ret;
}
void update(int x,int y,long long d)
{
	while (x <= n){
		dp[x][y] += d;
		x += lowbit(x);
	}

}
int main()
{
	int k;
	while (scanf("%d%d",&n,&k) != EOF){
		k++;
		CL(dp);
		for (int i = 1;i <= n;i++)
			scanf("%lld",&a[i]);
		
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= min(i+1,k);j++){
				if (j == 1)
					update(a[i],1,1);
				else{
					long long temp = Sum(a[i]-1,j-1);
					update(a[i],j,temp);
				}
			}
		}
	}
	return 0;
}





```
