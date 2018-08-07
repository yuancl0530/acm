#include<bits/stdc++.h>
using namespace std;

int T,k,ans,n,a[12],b[12];
char s[12];

void dfsmin(int r, int ti)
{
    if (r == n || ti == k)
    {
        int tmp = 0;
        for (int i=0;i<n;i++) tmp = tmp*10+b[i];
        ans = min(ans,tmp);
        return;
    }

    dfsmin(r+1,ti);
    for (int i=r+1;i<n;i++)
        if (b[i] < b[r])
        {
            swap(b[i],b[r]);
            dfsmin(r+1,ti+1);
            swap(b[i],b[r]);
        }
    return;
}

void dfsmax(int r, int ti)
{
    if (r == n || ti == k)
    {
        int tmp = 0;
        for (int i=0;i<n;i++) tmp = tmp*10+a[i];
        ans = max(ans,tmp);
        return;
    }

    dfsmax(r+1,ti);
    for (int i=r+1;i<n;i++)
        if (a[i] > a[r])
        {
            swap(a[i],a[r]);
            dfsmax(r+1,ti+1);
            swap(a[i],a[r]);
        }
    return;
}

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s %d",s,&k);
        n = strlen(s);
        int tmp = 0;
        for (int i=0;i<n;i++)
        {
            a[i] = b[i] = s[i]-'0';
            tmp = tmp*10+a[i];
        }
        if (k == 0)
        {
            printf("%d %d\n",tmp,tmp);
            continue;
        }
        ans = tmp;
        dfsmin(1,0);
        for (int i=1;i<n;i++)
        {
            if (b[i] != '0')
            {
                swap(b[i],b[0]);
                dfsmin(1,1);
                swap(b[i],b[0]);
            }
        }
        printf("%d ",ans);

        ans = tmp;
        dfsmax(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
