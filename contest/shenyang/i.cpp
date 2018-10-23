/*********************************
Date: Sat Sep  8 13:34:46 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x3f3f3f3f
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
char s[15];
char t[maxn];
bool code[maxn];
bool cd[maxn];
bool f[maxn];
int len[maxn];
int ask[maxn];
int ans[maxn];
int M[maxn];
int pr[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		int n,m;
		scanf("%d%d",&m,&n);
		int c;
		for (int i = 0;i < 1e6;++i) M[i] = 0;
		for (int i = 1;i <= n;++i){
			scanf("%d %s",&c,s);
			int tmp = 0;
			for (int j = 0;s[j];++j){
				tmp *= 3;
				tmp += s[j]-'0'+1;
			}
			M[tmp] = c+1;
		}
		scanf("%s",t);
		int cnt = 0;
		for (int i = 0;t[i];++i){
			int id;
			if (isdigit(t[i])) id = t[i]-'0';
			else id = t[i]-'A'+10;
			for (int i = 3;i >= 0;--i) code[cnt++] = id>>i & 1;
		}
		int cnt1 = 1;
		for (int i = 0;i*9+9 <= cnt;++i){
			int st = i*9;
			int jiao = 0;
			for (int j = 0;j < 9;++j) jiao ^= code[st+j];
			if (jiao){
				for (int j = 0;j < 8;++j) cd[cnt1++] = code[st+j];
			}
		}
		len[0] = 0;
		f[0] = true;
		int r = 0;
		for (int i = 1;i <= cnt1;++i) len[i] =pr[i]= 0,f[i]=false;
		for (int i = 1;i < cnt1;++i){
			int tmp = 0;
			int ed = min(cnt1,i+9);
			if (f[i-1])
			for (int j = i;j <= ed;++j){
				tmp *= 3;
				tmp += cd[j]+1;
				if (M[tmp]){
					if (len[j] < len[i-1] + 1){
						len[j] = len[i-1] + 1;
						f[j] = true;
						ask[j] = M[tmp] - 1;
						pr[j] = i-1;
					}
					if (len[j] >= m) {
						r = j;
						break;
					}
				}
			}
		}
		int cnt2 = 0;
		for (int i = r;i;i = pr[i])
			if (len[i] == m) {
				ans[cnt2++] = i;
				--m;
			}
		for (int i = cnt2-1;i >= 0;--i)
			printf("%c",ask[ans[i]]);
		printf("\n");
	}
	return 0;
}
