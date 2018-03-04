#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
#define CLR(a,b) memset(a,b,sizeof(a))
const int maxn=2;
struct node
{
    int x1,y1,x2,y2;
}rect[maxn];
int x[maxn],y[maxn];
bool vis[maxn][maxn];
int find(int *a,int ans,int n)
{
    int l=0,r=n-1;
    while(r>=l)
    {
        int m=l+(r-l)/2;
        if(a[m] == ans) return m;
        else if(a[m]>ans) r=m-1;
        else l=m+1;
    }
    return -1;
}

int main()
{
    int n,num1,num2,cnt;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0){
            cout<<"*"<<endl;
            return 0;
        }
        num1=num2=0;
        CLR(vis,0);
        CLR(x,0);
        CLR(y,0);
        cnt=num1=num2=0;
        for(int i=0;i<n;++i)
        {
            scanf("%d%d%d%d",&rect[i].x1,&rect[i].y1,&rect[i].x2,&rect[i].y2);
            x[num1++]=rect[i].x1;
            x[num1++]=rect[i].x2;
            y[num2++]=rect[i].y1;
            y[num2++]=rect[i].y2;
        }
        sort(x,x+num1);
        sort(y,y+num2);
        num1=unique(x,x+num1)-x;
        num2=unique(y,y+num2)-y;
        for(int i=0;i<n;++i)
        {
            int L_x=find(x,rect[i].x1,num1);
            int R_x=find(x,rect[i].x2,num1);
            int L_y=find(y,rect[i].y1,num2);
            int R_y=find(y,rect[i].y2,num2);
            for(int j=L_x;j<R_x;++j)
            for(int k=L_y;k<R_y;++k)
                vis[j][k]=true;
        }
        int ans=0;
        for(int i=0;i<num1;++i)
        for(int j=0;j<num2;++j)if(vis[i][j])
            ans += (x[i+1]-x[i])*(y[j+1]-y[j]);
        cout<<ans<<endl;
    }
    return 0;
}
