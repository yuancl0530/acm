#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<math.h>
#include<limits.h>
#include<stack>
#include<queue>
#define LL long long
using namespace std;
LL f[50005]={0};
int a[50005]={0};
int main()
{
    int n;
    LL amax;
    scanf("%d",&n);
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>=0) flag=true;
    }
    if(flag==false)
    {
        printf("0\n");
        return 0;
    }
    f[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        f[i]=max((LL)a[i],f[i-1]+a[i]);
    }
    amax=f[1];
    for(int i=2;i<=n;i++)
    {
        //printf("%d ",f[i]);
        if(amax<f[i]) amax=f[i];
    }
    printf("%d\n",amax);

    return 0;
}

