/*********************************
Date: Mon Nov 13 19:59:20 CST 2017
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
#define INFLL 0x7fffffffffffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
char s[maxn],t[maxn],tmp[maxn],str1[maxn],str2[maxn];
int Next[maxn];
void getNext(char *s)
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
int solve(char *a,char *b,char *str1)
{
	//a+b
	strcpy(tmp,b);
	strcat(tmp,a);
	getNext(tmp);
	int lena=strlen(a);
	int lenb=strlen(b);
	int i=strlen(tmp)-1;
	while (i>=lenb || i>lena-1) i=Next[i];
	strcpy(str1,a);
	strcat(str1,b+i+1);
	return i;
}
int main()
{
	while (scanf("%s%s",s,t)!=EOF){
		int n1=solve(s,t,str1);
		int n2=solve(t,s,str2);
//		cout<<str1<<" "<<str2<<endl;
		if (n1>n2){
			printf("%s\n",str1);
		}
		else if (n1<n2){
			printf("%s\n",str2);
		}
		else{
			if (strcmp(str1,str2)<0)
				printf("%s\n",str1);
			else
				printf("%s\n",str2);
		}
	}
	return 0;
}
