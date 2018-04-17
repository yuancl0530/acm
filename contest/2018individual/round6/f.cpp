/*********************************
Date: Wed Apr 11 20:09:03 CST 2018
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
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
int next[maxn],pre[maxn];
char s[maxn];
char op[maxn];
int main()
{
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	scanf("%s",s+1);
	int len=strlen(s+1);
	for (int i=0;i<=n;++i){
		next[i]=i+1;
	}
	for (int i=n+1;i>0;--i){
		pre[i]=i-1;
	}
	pre[0]=0;
	scanf("%s",op);
	for (int i=0;op[i];++i){
		if (op[i]=='L')
			p=pre[p];
		else if (op[i]=='R')
			p=next[p];
		else{
			if (s[p]=='('){
				int cnt=1;
				for (int j=next[p];j!=n+1;j=next[j]){
					if (s[j]=='(') ++cnt;
					else --cnt;
					if (cnt==0){
						int l=pre[p];
						int r=next[j];
						next[l]=r;
						pre[r]=l;
						p=r;
						if (p==n+1){
							p=pre[n+1];
						}
						break;
					}
				}
			}
			else {
				int cnt=1;
				for (int j=pre[p];j;j=pre[j]){
					if (s[j]==')') ++cnt;
					else --cnt;
					if (cnt==0){
						int l=pre[j];
						int r=next[p];
						next[l]=r;
						pre[r]=l;
						p=r;
						if (p==n+1){
							p=pre[n+1];
						}
						break;
					}
				}
			}
		}
	}
	for (int i=next[0];i!=n+1;i=next[i]){
		printf("%c",s[i]);
	}
	printf("\n");
	return 0;
}
