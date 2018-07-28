/*********************************
Date: Fri Jul 27 19:40:52 CST 2018
Author: ycl
*********************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x3f3f3f3f
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
int wa[maxn],wb[maxn],wu[maxn],wv[maxn],height[maxn],sa[maxn];
char s[maxn];
char in[110][1010];
bool cmp(int *y,int a,int b,int j)
{
	return y[a] == y[b] && y[a+j] == y[b+j];
}
void Suffix(int n,int m)
{
	int *x = wa,*y = wb,i,j,p;
	for (i = 0;i < m;++i) wu[i] = 0;
	for (i = 0;i < n;++i) ++wu[x[i]=s[i]];
	for (i = 1;i < m;++i) wu[i] += wu[i-1];
	for (i = n-1;i >= 0;--i) sa[--wu[x[i]]] = i;
	for (p = j = 1;p < n;j <<= 1,m = p){
		for (p = 0,i = n-j;i < n;++i) y[p++] = i;
		for (i = 0;i < n;++i) if (sa[i] >= j) y[p++] = sa[i] - j;
		for (i = 0;i < n;++i) wv[i] = x[y[i]];
		for (i = 0;i < m;++i) wu[i] = 0;
		for (i = 0;i < n;++i) ++wu[wv[i]];
		for (i = 1;i < m;++i) wu[i] += wu[i-1];
		for (i = n-1;i >= 0;--i) sa[--wu[wv[i]]] = y[i];
		swap(x,y);
		for (x[sa[0]] = 0,p = i = 1;i < n;++i)
			x[sa[i]] = cmp(y,sa[i-1],sa[i],j)? p-1:p++;
	}
	--n;
	x = wa;
	for (int i = 1;i <= n;++i) x[sa[i]] = i;
	for (p =  i = 0;i < n;height[x[i++]] = p)
		for (p? --p:0,j = sa[x[i]-1];s[i+p] == s[j+p];++p);
}
int len[1010];
bool vs[1100];
int n,m;
int getid(int x)
{
	int t = 0;
	while (x >= len[t] && t+1 < n){
		x -= len[t++];
	}
	return t;
}
vector<int> ans;
int tmp[maxn];
bool check(int k)
{
	int cnt = 0;
	bool flag = 0;
	int t = 0;
	for (int i = 1;i <= m;++i){
		if (height[i] >= k){
			int t1 = getid(sa[i-1]);
			int t2 = getid(sa[i]);
			if (t1 == t2) continue;
			if (!vs[t1]){
				vs[t1] = true;
				++cnt;
			}
			if (!vs[t2]){
				vs[t2] = true;
				++cnt;
			}
			if (cnt > n/2 && !flag){
				tmp[t++] = sa[i];
				flag = true;
			}
		}
		else{
			cnt = 0;
			flag = false;
			for (int i = 0;i <= n;++i)
				vs[i] = 0;
		}
	}
	if (t){
		ans.clear();
		for (int i = 0;i < t;++i)
			ans.push_back(tmp[i]);
		return true;
	}
	return false;
}
int main()
{
	bool tag = 0;
	while (scanf("%d",&n) != EOF && n){
		m = 0;
		if (tag){
			printf("\n");
		}
		tag = 1;
		for (int i = 0;i < n;++i)
			scanf("%s",in[i]);
		for (int i = 0;i < n;++i){
			for (int j = 0;in[i][j];++j)
				s[m++] = in[i][j];
			len[i] = strlen(in[i])+1;
			s[m++] = '*';
		}
		if (n == 1){
			printf("%s\n",in[0]);
			continue;
		}
		s[--m] = 0;
		Suffix(m+1,256);
		for (int i = 2;i <= m;++i){
			int t = 0;
			for (int j = 0;j < height[i];++j){
				if (s[sa[i]+j] != '*') ++t;
				else break;
			}
			height[i] = t;
		}
		int l = 0;
		int r = m;
		while (l + 1 < r){
			int mid = (l+r)>>1;
			if (check(mid))
				l = mid;
			else
				r = mid;
		}
		if (l){
			for (int i = 0;i < ans.size();++i){
				int v = ans[i];
				for (int j = 0;j < l;++j)
					printf("%c",s[v+j]);
				printf("\n");
			}
		}
		else
			printf("?\n");
	
	}
	return 0;
}
