/*********************************
Date: Mon Mar 26 14:32:32 CST 2018
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
const int maxn = 2e5 + 100;
int Next[maxn];
char a[maxn],b[maxn],s[maxn];
void getNext()
{
	int k=-1;
	Next[0]=k;
	for (int i=1;s[i];++i){
		while (k>=0 && s[k+1]!=s[i])
			k=Next[k];
		if (s[k+1]==s[i])
			++k;
		Next[i]=k;
	}
}
int solve(char *a,char *b)
{
	int lena=strlen(a);
	int lenb=strlen(b);
	int lens=lena+lenb;
	strcpy(s,b);
	strcat(s,a);
	getNext();
	int t=Next[lens-1];
	while (t>=lena||t>=lenb) t=Next[t];
	return t;
}
int main()
{
	while (scanf("%s%s",a,b)!=EOF){
		int t1=solve(a,b);
		int t2=solve(b,a);
		if (t1>t2 || t1==t2&&strcmp(a,b)<0){
			strcat(a,b+t1+1);
			printf("%s\n",a);
		}
		else {
			strcat(b,a+t2+1);
			printf("%s\n",b);
		}
	}
	return 0;
}
