/*********************************
Date: Sun Apr 15 12:45:26 CST 2018
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
char dic[][10]={
"Alfa","Bravo","Charlie","Delta","Echo","Foxtrot","Golf",
"Hotel","India","Juliett","Kilo","Lima","Mike","November",
"Oscar","Papa","Quebec","Romeo","Sierra","Tango","Uniform",
"Victor","Whiskey","Xray","Yankee","Zulu","Zero","One",
"Two","Three","Four","Five","Six","Seven","Eight","Nine"
};
int getId(char ch)
{
	ch=tolower(ch);
	if (ch>='a' && ch<='z'){
		return ch-'a';
	}
	return 26+ch-'0';
}
char s[maxn];
int main()
{
	while (scanf("%s",s)!=EOF){
		printf("CQCQCQ this is %s",s);
		for(int i=0;s[i];++i){
			printf(" %s",dic[getId(s[i])]);
		}
		printf(" %s\n",s);
	}
	return 0;
}
