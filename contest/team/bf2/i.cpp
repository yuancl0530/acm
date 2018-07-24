#include<bits/stdc++.h>
using namespace std;

const int maxn = 550;
struct node
{
    int a,b;
    node (int A=0,int B=0)
    {
        a = A, b = B;
    }
};
vector<node> vec[maxn];
int n,h,w;

void solve(int m)
{
    int x = 0, y = 0;
    vec[1].push_back(node(1,1));
    x = 2, y = 2;
    for (int i=3;i<=n;i+=2,x++,y++)
    {
        for (int j=1;j<=x;j++) vec[i].push_back(node(x,j));
        for (int j=x-1;j>0;j--) vec[i].push_back(node(j,y));
    }
    int Y = y;
    x = 1;
    for (int i=m-1;i>0;i-=4)
    {
        for (int j=y;j<=w;j++) vec[i].push_back(node(x,j));
        for (int j=w;j>=y;j--) vec[i].push_back(node(x+1,j));
        x+=2,y+=2;
    }
    x = 3, y = Y;
    for (int i=m-3;i>0;i-=4)
    {
        for (int j=x;j<=h;j++) vec[i].push_back(node(j,y));
        for (int j=h;j>=x;j--) vec[i].push_back(node(j,y+1));
        x+=2,y+=2;
    }
}

void print()
{
    //int f[maxn][maxn];
    //memset(f,0,sizeof(f));
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<vec[i].size();j++)
        {
            int x = vec[i][j].a, y = vec[i][j].b;
            printf("%d %d ",x,y);
            //f[x][y] = i;
        }
        printf("\n");
    }
    /*for (int i=1;i<=h;i++)
    {
        for (int j=1;j<=w;j++) printf("%d ",f[i][j]);
        printf("\n");
    }*/
}

int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=1;i<=n;i++) vec[i].clear();
        int m = n;
        if (n % 2)
            h = (n+1)>>1, w = n;
        else
            h = n>>1, w = n-1, m--;

        solve(m);
        if (n % 2==0)
        {
            w += 2;
            for (int j=h;j>0;j--) vec[n].push_back(node(j,w-1));
            for (int j=1;j<=h;j++) vec[n].push_back(node(j,w));
        }

        print();
    }
    return 0;
}
