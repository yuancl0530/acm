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
int fb[maxn],pr[maxn],mu[maxn],phi[maxn],mus[maxn];

void oula_prime(int n)
{
	CL(fb);
	for (int i = 1;i <= n;i++){
		if (!fb[i]){fb[i] = i,pr[++pr[0]] = i,mu[i] = -1,phi[i] = }
		for (int j = 1;j <= pr[0];j++){
			int k = i * pr[j];
			if (k > n) break;
			fb[k] = pr[j];
			if (i % pr[j] == 0){
				mu[k] = 0,phi[k] = phi[i] * phi[j];
				break;
			}
			else{
				mu[k] = -mu[i],phi[k] = phi[i] * (pr[j] - 1);
			}
		}
	}
	mus[0] = 0;
	for (int i = 0;i <= n;i++){
		mus[i] = mus[i-1] + mu[i];
	}
}
int main()
{



	return 0;
}
