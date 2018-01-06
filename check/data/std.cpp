/*********************************
Date: Sat Nov 18 09:33:43 CST 2017
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
char str[][10]={
	".-","-...","-.-.","-..",
	".","..-.","--.","....",
	"..",".---","-.-",".-..",
	"--","-.","---",".--.",
	"--.-",".-.","...","-",
	"..-","...-",".--","-..-",
	"-.--","--..","-----",".----",
	"..---","...--","....-",".....",
	"-....","--...","---..","----."
};
int getId(char ch)
{
	if (ch >='a' && ch <= 'z')
		return ch-'a';
	else if (ch >= 'A' && ch <= 'Z')
		return ch-'A';
	else 
		return 26+ch-'0';
}
char s[maxn];
int main()
{
	int T,n;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=0;i<n;++i){
			scanf("%s",s);
			for (int j=0;s[j];++j)
				printf("%s ",str[getId(s[j])]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
