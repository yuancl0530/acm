/*********************************
Date: Tue Sep  5 19:54:58 CST 2017
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
int next[maxn];
char s[maxn];
char str[maxn];
void getNext(char *s,int *next)
{
	int k=0;
	int len=strlen(s);
	for (int i=0;i<len;i++){
		while (k>0&&s[k]!=s[i])
			k=next[k];
		if (s[i]==s[k])
			++k;
		next[i]=k;
	}
}
int KMPMatch(char *s,char *str,int *next)
{
	getNext(s,next);
	int len=strlen(s);
	int k=0;
	for (int i=0;str[i];++i){
		while (k>0&&s[k]!=str[i])
			k=next[k];
		if (s[k]==str[i])
			k++;
		if (k==len) return i-len+1;
	}
	return -1;
}
int main()
{
	cin>>str>>s;
	cout<<KMPMatch(s,str,next)<<endl;


	return 0;
}
