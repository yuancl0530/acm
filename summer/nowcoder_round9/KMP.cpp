#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e5 + 100;
const int INF = 1e5+100;
int cur;
struct Str
{
	char s[maxn];
	int next[maxn];
	int stk[maxn];
	int len;
	void init()
	{
		int k=-1;
		len=strlen(s);
		next[0]=-1;
		for (int i=1;i<len;++i){
			while (k>=0 && s[i]!=s[k+1])
				k=next[k];
			if (s[i]==s[k+1])
				++k;
			next[i]=k;
		}
	}
	int solve(char t)
	{
		int p;
		if (cur < 0) return len;

		if (cur == 0) p = -1;
		else p = stk[cur-1];

		while (p >=0 && t != s[p+1]) p = next[p];
		if (t == s[p+1]) ++p;
		stk[cur] = p;
		//cout<<s<<" "<<p<<endl;
		if (p == -1) return len;
		return len-p-1;
	}
}str[5];
int n;
char q[maxn];
char s[maxn];
void getans(char ch=0)
{
	int ans = INF;
	for (int i = 0;i < n;++i)
		ans = min(ans,str[i].solve(ch));
	printf("%d\n",ans);
}
int main()
{
	scanf("%d",&n);
	for (int i = 0;i < n;++i){
		scanf("%s",str[i].s);
		str[i].init();
	}
	scanf("%s",s);
	cur = -1;
	getans();
//	cout<<endl;
	for (int i = 0;i < s[i];++i){
		if (s[i]=='-') --cur;
		else q[++cur] = s[i];
		if (cur < 0) cur = -1;
		char ch = cur>=0? q[cur]:0;
//		cout<<i<<":"<<q<<endl;
		getans(ch);
//		cout<<endl<<endl;
	}
	return 0;
}
