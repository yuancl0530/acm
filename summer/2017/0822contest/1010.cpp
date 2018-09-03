/*********************************
Date: Tue Aug 22 12:07:49 CST 2017
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
char a[maxn],b[maxn];
bool match()
{
	int lena = strlen(a);
	int lenb = strlen(b);
	int s=-1;
	char c=0;
	int len;
	for (int i=0;i<lenb;i++){
		if (b[i]!='.'&&b[i]!='*')c=b[i];
		if (b[i]=='*'){len=i;s=i;break;}
	}
	if (s==-1){
		if (lenb!=lena)return false;
		s=lenb;
		len=lena;
	}
	else if (lenb>lena+1)return false;
	
	for (int i=0;i<len;i++){
		if (a[i]==b[i]||b[i]=='.')
			continue;
		else
			return false;
	}
	if (s!=lenb){
		for (int i=1;b[lenb-i]!='*';i++){
			if (a[lena-i]==b[lenb-i]||b[lenb-i]=='.')
				continue;
			else
				return false;
		}
		for (int i=s;i<lena-(lenb-s-1);i++){
			if (a[i]!=c&&c!='.')return false;
		}
	}
	return true;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		CL(a);
		CL(b);
		scanf("%s%s",a,b);
		if (match()){
			printf("yes\n");
		}
		else{
			printf("no\n");
		}
	}

	return 0;
}
