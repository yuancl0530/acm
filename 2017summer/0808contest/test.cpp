#include<stdio.h>
#include<string.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

const int maxn = 2*1e4;
int T,n,m,tot,num,ans[60];
long long b[maxn],f[maxn];

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d %d",&n,&m);
        for (int i=0;i<=m;i++)
            scanf("%I64d",&b[i]);
        int k = 0;
        memset(f,0,sizeof(f));
        f[0] = 1;
		tot = 0;
        for (int i=1;i<=m;i++)
        {
            b[i] -= f[i];
            if (b[i])
            {
                num = b[i];
                while (num)
                {
                    ans[++k] = i;
                    tot += i;
                    for (int j=tot;j>=i;j--)
                        f[j] = f[j-i] + f[j];
                    /*for (int j=0;j<=tot;j++)
                        printf("%d ",f[j]);
                    printf("\n");*/
                    num--;
                    if (k == n) break;
                }
            }
            if (k == n) break;
        }
        for (int i=1;i<=n;i++)
			if (i==1)printf("%d",ans[i]);
			else printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}
