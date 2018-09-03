/*********************************
Date: Sat Aug 19 13:52:37 CST 2017
*********************************/
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
LL p[40][40];
void Init()
{
	for (int i = 2;i <= 36;i++){
		p[i][0] = 1;
		for (int j = 1;j <= 40;j++){
			p[i][j] = p[i][j-1]*i;
			if (p[i][j]>INF) break;
		}
	}
}
LL cal(int n,int m)//m进制
{	
	int i;
	int t = 0;
	int ret = 0;
	if (n<m) return m*n;
	if (n==m) return m*(n-1)+1;
	for (i = 0;;i++)
		if (p[m][i+1]>n)break;
	if (i&1){
		t+=p[m][i/2+1]+p[m][i/2]-2;
	}
	else{
		t+=2*p2[m][i/2]-2;
	}
	int res=n-p[m][i]-1;
	if (res==0) return n-t+t*m;
	int temp;
	if (i&1){
		temp=p[m][i/2]+p[m][i/2-1];
	}
	else{
		temp=p[m][i/2];
	}
	t+=res/temp+1;
	return t*m+n-t;
}
int main()
{
	int T;
	int L,R,l,r;
	scanf("%d",&T);
	Init();
	while (T--){
		scanf("%d%d%d%d",&L,&R,&l,&r);
		LL ans = 0;
		for (int i = l;i <= r;i++){
			//cout<<cal(R,i)<<endl;
			//cout<<cal(L-1,i)<<endl;
			ans+=cal(R,i)-cal(L-1,i);
		}
		cout<<ans<<endl;
	}
	return 0;
}
