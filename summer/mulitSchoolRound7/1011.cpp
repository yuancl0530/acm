#include<bits/stdc++.h>
using namespace std;

#define FI(n) FastIO::read(n)
namespace FastIO {
    const int SIZE = 1 << 16;
    char buf[SIZE], obuf[SIZE], str[60];
    int bi = SIZE, bn = SIZE, opt;
    int read(char *s) {
        while (bn) {
            for (; bi < bn && buf[bi] <= ' '; bi++);
            if (bi < bn) break;
            bn = fread(buf, 1, SIZE, stdin);
            bi = 0;
        }
        int sn = 0;
        while (bn) {
            for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
            if (bi < bn) break;
            bn = fread(buf, 1, SIZE, stdin);
            bi = 0;
        }
        s[sn] = 0;
        return sn;
    }
    bool read(int& x) {
        int n = read(str), bf;

        if (!n) return 0;
        int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
        for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
        if (bf < 0) x = -x;
        return 1;
    }
};

const int maxn = 1e5+100;
struct node
{
    int idx,w;
    node (int i=0, int j=0)
    {
        idx = i, w = j;
    }
    friend bool operator < (const node n1,const node n2)
    {
        return n1.w < n2.w;
    }
}a[6][maxn];
int b[maxn][6],v[6];
int T,n,k,f[6],num[maxn],bet[maxn];
int q[maxn];

void solve()
{
    int up = (1<<k)-1;
    int cnt = 0;//beat number

    for (int i=0;i<k;i++)
    {
        b[n][i] = 0;
        f[i] = 0;
    }

    int l = 0, r = 0;
    q[r++] = n;
    while (l < r)
    {
        cnt++;
        int u = q[l++];
        for (int i=0;i<k;i++) v[i] += b[u][i];

        for (int i=0;i<k;i++)
        {
            int start = f[i];
            for (int j=start;j<num[i];j++)
            {
                if (a[i][j].w <= v[i])
                {
                    int id = a[i][j].idx;
                    bet[id] = bet[id] | (1<<i);
                    if (bet[id] == up) q[r++] = id;
                    f[i]++;
                }
                else break;
            }
        }
    }
    printf("%d\n",cnt-1);
    for (int i=0;i<k;i++) 
		if (i) printf(" %d",v[i]);
		else printf("%d",v[i]);
	printf("\n");
    return;
}

int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d",&T);
    while (T--)
    {
        FI(n);
		FI(k);
        for (int i=0;i<k;i++) FI(v[i]);

        for (int i=0;i<k;i++) num[i] = 0;
        for (int i=0;i<n;i++)
        {
            bet[i] = 0;
            for (int j=0;j<k;j++)
            {
                int c;
                FI(c);
                a[j][num[j]++] = node(i,c);
            }
            for (int j=0;j<k;j++) FI(b[i][j]);
        }
        for (int i=0;i<k;i++)
            sort(a[i],a[i]+num[i]);

        solve();
    }
    return 0;
}
