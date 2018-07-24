/*********************************
Date: Tue Mar 13 22:00:01 CST 2018
Author: ycl
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
#include <set>
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define LL long long
#define N 401
const int mod = 1e9 + 7;
const int maxn = 1e3+10;
int a[maxn];
int b[maxn];
int n;
LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if (b==0){
		x = 1;
		y = 0;
		return a;
	}
	LL t= exgcd(b,a%b,x,y);
	LL tmp = x;
	x = y;
	y = tmp-a/b*y;
	return t;
}
LL inv(LL v, LL p)
{
	LL x,y;
	LL t = exgcd(v,p,x,y);
	if (t != 1) return 0;
	return (x+p)%p;
}
int gcd(int a,int b)
{
	if (b == 0) return a;
	return gcd(b,a%b);
}
vector<pair<LL,LL> > V;
bool Merge(LL a,LL n1,LL b,LL n2)
{
	LL d = gcd(n1,n2);
	LL c = b-a;
	if (c%d)
		return false;
	c = (c%n2+n2)%n2;
	c /= d;
	n1 /= d;
	n2 /= d;
	c *= inv(n1,n2);
	c %= n2;
	c *= n1*d;
	c += a;
	LL n3 = n1*n2*d;
	V.push_back(MP((c%n3+n3)%n3,n1*n2*d));
	return true;
}
LL solve()
{
	V.clear();
	for (int i=0;i<n;++i)
		b[i]=i+1;
	int t=-1;
	for (int i=0;i+1<n;++i){
		int cnt = 0;
		while (1) {
			++t;
			t=(t+n)%n;
			if (b[t]==0)continue;
			++cnt;
			if (t+1==a[i])break;
		}
		b[a[i]-1] = 0;
		V.push_back(MP(cnt%(n-i),n-i));
	}

	for (int i=0;i<V.size();++i){
		for (int j=0;j<i;++j){
			if (V[i].first >=0 && V[j].first >=0){
				if (gcd(V[i].second,V[j].second) != 1){
					if (Merge(V[i].first,V[i].second,V[j].first,V[j].second)){
						V[i].first = V[j].first = -1;
						break;
					}
					else
						return 0;
				}
			}
		}
	}

	LL M=1;
	LL ans = 0;
	for (int i=0;i<V.size();++i){
		if (V[i].first != -1)
			M*=V[i].second;
	}

	for (int i=0;i<V.size();++i){
		if (V[i].first == -1 ) continue;
		LL tmp = inv(M/V[i].second,V[i].second);
		if (!tmp) return 0;
		ans += V[i].first*tmp*(M/V[i].second);
	}

	ans = (ans%M+M)%M;
	if (ans == 0)
		ans += M;
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=0;i<n;++i){
			int t;
			scanf("%d",&t);
			a[t-1] = i+1;
		}
		LL ans = solve();
		if (ans==0)
			printf("Creation August is a SB!\n");
		else
			printf("%lld\n",ans);
	}
	return 0;
}
