/*********************************
Date: Sat Mar  3 13:31:05 CST 2018
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
#include <list>
#include <set>
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
pair<int,int> M[maxn];
char s[maxn];
void solve(char *s)
{
	stack<pair<int,int> >S;
	LL ans = 0;
	for (int i=0;s[i];++i){
		if (s[i]=='(') continue;
		if (s[i]==')'){
			pair<int,int>p,q;
			q = S.top();
			S.pop();
			if (S.empty()) break;
			p = S.top();
			S.pop();
			if (p.second != q.first){
				printf("error\n");
				return ;
			}
			ans += (LL)p.first*p.second*q.second;
			S.push(MP(p.first,q.second));
		}
		else{
			S.push(M[s[i]-'A']);
		}
	}
	printf("%lld\n",ans);
}
int main()
{
	int n;
	scanf("%d",&n);
	char a;
	int p,q;
	for (int i=0;i<n;++i){
		cin>>a>>p>>q;
		M[a-'A'] = MP(p,q);
	}
	while (scanf("%s",s) != EOF){
		solve(s);
	}
	return 0;
}
