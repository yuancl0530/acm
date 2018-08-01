#include<bits/stdc++.h>
using namespace std;

int T,Q,n,nx,ny,mx,my;
int m[2100][2100],a[30];

void get()
{
    int cursor = 0;
    for (int i=0; i<=2000; i++)
        for (int j=0; j<=i; j++)
        {
            m[j][i-j] = a[cursor];
            cursor = (cursor+1) % n;
        }
    return;
}

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%d",&a[i]);

        get();

        scanf("%d",&Q);
        while (Q--)
        {
            scanf("%d %d %d %d",&nx,&ny,&mx,&my);
            long long ans = 0;
            for (int i=nx; i<=mx; i++)
                for (int j=ny; j<=my; j++)
                ans += m[i][j];
            printf("%lld\n",ans);
        }
    }
    return 0;
}
