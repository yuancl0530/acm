/*********************************
Date: Fri Aug 25 15:41:35 CST 2017
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
int next[maxn];
char a[maxn];
char b[maxn];
void getNext(char *p,int *next)
{
	int i=1;
	int k=-1;
	next[0]=-1;
	int len = strlen(p);
	while (i<len){
		if (k==-1||p[i]==p[k]){
			++k;
			++i;
			next[i]=k;
		}
		else{
			k=next[k];
		}
	}
}
int KMPMatch(char *s,char *p)
{
	CL(next);
	int i=0;
	int j=0;
	getNext(p,next);
	int lens=strlen(s);
	int lenp=strlen(p);
	while (i<lens){
		if (j==-1 || s[i]==p[j]){
			++j;
			++i;
		}
		else{
			j=next[j];
		}
		if (j==lenp)
			return i-lenp;
	}
	return -1;
}
int main()
{
	while (cin>>a>>b){
		cout<<KMPMatch(a,b)<<endl;
	}
	return 0;
}
