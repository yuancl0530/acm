/*********************************
Date: Wed Apr 11 20:31:33 CST 2018
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
char s[maxn];
int num[10];
char s1[maxn];
int num2[10];
int len;
bool check(int t)
{
	int nn=t;
	CL(num2);
	int cnt=0;
	while (t){
		++cnt;
		++num2[t%10];
		t/=10;
	}
	if (len-cnt!=nn) return false;
	int k=0;
	for (int i=0;i<10;++i){
		if (i && num[i])k++;
		if (num[i]<num2[i])
			return false;
	}
	if (k==0) return false;
	return true;
}
char ans[maxn];
int main()
{
	scanf("%s%s",s,s1);
	len=strlen(s);
	for (int i=0;s[i];++i){
		++num[s[i]-'0'];
	}
	for (int i=0;s1[i];++i){
		--num[s1[i]-'0'];
	}
	int l;
	for (int i=1;i<len;++i){
		if (check(i)){
			l=i;
		}
	}
	int t=l;
	while (t){
		--num[t%10];
		t/=10;
	}

	t=0;
	for (int i=1;i<10;++i){
		if (num[i]){
			ans[t++]=i;
			--num[i];
			break;
		}
	}
	if (t==0){
		printf("%s",s1);
		for (int i=0;i<10;++i){
			while (num[i]){
				printf("%d",i);
				--num[i];
			}
		}
		return 0;
	}

	for (int i=0;i<10;++i){
		while (num[i]){
			ans[t++]=i;
			--num[i];
		}
	}

	int len2=strlen(s1);
	#ifdef DEBUG
	for (int i=0;i<t;++i){
		printf("%d",ans[i]);
	}
	printf("\n");
	#endif
	int k=s1[0]=='0'? 1:0;
	if (s1[0]!='0' && len2>t){
		if (s1[0]-'0'<ans[0]){
			printf("%s",s1);
		}
		for (int i=0;i<t;++i)
			printf("%d",ans[i]);
		if (s1[0]-'0'>=ans[0]){
			printf("%s",s1);
		}
		printf("\n");
		return 0;
	}
	for (int i=k;i<t;++i){
		int f=1;
		if (i+len2>t) break;
		for (int j=0;f&&  i+j<t && s1[j];++j){
			if (s1[j]-'0'>ans[i+j]) {
				f=0;
				break;
			}
			else if (s1[j]-'0'<ans[i+j]){
				break;
			}
		}
		if (f) {
			for (int j=0;j<i;++j){
				printf("%d",ans[j]);
			}
			printf("%s",s1);
			for (int j=i;j<t;++j){
				printf("%d",ans[j]);
			}
			printf("\n");
			return 0;
		}
	}
	for (int i=0;i<t;++i){
		printf("%d",ans[i]);
	}
	printf("%s",s1);
	printf("\n");
	
	return 0;
}
