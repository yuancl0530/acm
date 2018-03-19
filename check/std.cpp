#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long LL;
const int low(int x) { return x&-x; }
const int INF = 0x7FFFFFFF;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
int T, n, x[maxn], y;
LL a[maxn], b[maxn], vis[maxn];

void egcd(LL a, LL b, LL&d, LL&x, LL&y)
{
	if (!b) { d = a, x = 1, y = 0; }
	else
	{
		egcd(b, a%b, d, y, x);
		y -= x*(a / b);
	}
}

LL lmes() {
	LL M = a[1], R = b[1], x, y, d;
	for (int i = 2; i <= n; i++) {
		egcd(M, a[i], d, x, y);
		if ((b[i] - R) % d) return -1;
		x = (b[i] - R) / d*x % (a[i] / d);
		R += x*M;
		M = M / d*a[i];
		R %= M;
	}
	return (R + M) % M ? (R + M) % M : M;
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			a[i] = n - i + 1;
			vis[i] = 0;
			scanf("%d", &y);
			x[y] = i;
		}
		for (int i = 1, j = 1, k; i <= n; i++)
		{
			for (k = 1; j != x[i];) { if (!vis[j]) k++; j = j % n + 1; }
			vis[x[i]] = 1;    b[i] = k % a[i];
		}
		LL k = lmes();
		if (k == -1) printf("Creation August is a SB!\n");
		else cout << k << endl;
	}
	return 0;
}
