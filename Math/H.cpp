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
const int maxn = 1e7 + 100;
bool isprime[maxn];
int prime[maxn];
int pi[maxn];
void oula()
{
	Cl(isprime,1);
	for (int i = 2;i < maxn;i++){
		if (isprime[i])
			prime[++prime[0]] = i;
		for (int j = 1;j <= prime[0];j++){
			int k = prime[j]*i;
			if (k > maxn) break;
			isprime[k] = 0;
			if (i % prime[j] == 0)
				break;
		}
	}
	for (int i = 2;i < maxn;i++)
		pi[i] = pi[i-1] + (int)isprime[i];
}
int p[maxn];
int rub[maxn];
void pa()
{
	for (int i = 1;i < maxn;i++){
		int t = i;
		int cmp = 0;
		while (t){
			cmp = 10*cmp + t%10;
			t/=10;
		}
		if (cmp == i){
			p[++p[0]]  = i;
			rub[i] = rub[i-1] + 1;
		}
		else{
			rub[i] = rub[i-1];
		}
	}
}
int main()
{
	oula();
	pa();
	int p,q;
	while (cin >> p >> q){
		int ans = -1;
		for (int i = 1;i < 2e6 ;i++){
			if (q*pi[i] <= p*rub[i]){
				ans = i;
			}
		}
		if (ans != -1)
			cout << ans << endl;
		else
			cout<<"Palindromic tree is better than splay tree"<<endl;
	}

	return 0;
}
