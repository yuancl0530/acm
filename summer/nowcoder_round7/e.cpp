/*********************************
Date: Thu Aug  9 13:26:33 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x3f3f3f3f
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
int p[maxn];
inline int c4(int x)
{
	return x*(x-1)*(x-2)*(x-3)/24;
}
int cnt = 0;
vector<int>G[maxn];
bool vs[100][100];
int main()
{
	int n = 0;
	int k = 100000;
	for (int i = 1;i <= 75;++i)
		cout << c4(i)<<endl;
	/*int k;
	int m = 4;
	scanf("%d",&k);
	int v = 0;
	while (c4(m) <= k) ++m;
	if (c4(m)>k) --m;

	for (int i = 1;i <= m;++i){
		for (int j=i+1;j <= m;++j){
			G[i].push_back(j);
			vs[i][j] = 1;
			++v;
		}
	}
	k -= c4(m);
	for (int i = 1;i <= m;++i){
		for (int j = i+1;j <= m;++j)
			for (int k = j+1;k <= m;++k)
				p[cnt++] = i*10000+j*100+k;
	}
	int t = m;
	while (k>0){
		++t;
		for (int i = 0;k>0 && i < cnt;++i){
			--k;
			int x = p[i];
			cout<<x<<endl;
			cout<<x<<endl;
			for (int j=0;j < 3;++j,x/=100){
				if (!vs[t][x%100]) {
					++v;
					G[t].push_back(x%100);	
				}
				vs[t][x%100] = 1;
			}
		}
	}
	printf("%d %d\n",t,v);
	for (int i = 1;i <= t;++i){
		for (int j = 0;j < G[i].size();++j)
			printf("%d %d\n",i,G[i][j]);
	}*/
	return 0;
}
