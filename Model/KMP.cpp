#include <bits/stdc++.h>
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
	int k=-1;
	int len=strlen(s);
	next[0]=-1;
	for (int i=1;i<len;++i){
		while (k>=0&&s[k+1]!=s[i]) k=next[k];
		if (s[k+1]==s[i]) ++k;
		next[i]=k;
	}
}
int KMPmatch(char *s,char *str,int *next)
{
	getNext(s,next);
	int len=strlen(s);
	int k=-1;
	for (int i=0;str[i];++i){
		while (k>=0&&s[k+1]!=str[i]) k=next[k];
		if (s[k+1]==str[i]) ++k;
		if (k+1==len)
			return i-len+1;
	}
}
int main()
{
	cin>>str>>s;
	cout<<KMPmatch(s,str,next)<<endl;
	return 0;
}
