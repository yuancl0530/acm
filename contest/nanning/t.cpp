#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct node { int x,y; }pre[100][100],ans[1000];
double a,b,dp[100][100],d[100][100];
int n,m;
string str;
int main()
{
    scanf("%lf",&a);
    scanf("%lf",&b);
	getchar();
	n=0;
    while (getline(cin,str)){
		++n;
		m=1;
		stringstream ss;
		ss<<str;
		while (ss>>d[n][m])
			++m;
	}
	--m;
	cout<<n<<" "<<m<<endl;
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;j++)
			cout<<d[i][j]<<" ";
		cout<<endl;
	}




    for (int i=0;i<=n;i++)
        for (int j=0;j<=m;j++) dp[i][j] = 1e9;
    dp[1][1] = d[1][1];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            double tmp = 0;
            if (i!=1 && j!=1)
            {
                tmp = dp[i-2][j-1] + a*(d[i-1][j]+d[i][j]);
                if (tmp < dp[i][j])
                {
                    dp[i][j] = tmp;
                    pre[i][j].x = i-2;
                    pre[i][j].y = j-1;
                }
                tmp = dp[i-1][j-1] + b*d[i][j];
                if (tmp < dp[i][j])
                {
                    dp[i][j] = tmp;
                    pre[i][j].x = i-1;
                    pre[i][j].y = j-1;
                }
                tmp = dp[i-1][j-2] + a*(d[i][j-1]+d[i][j]);
                if (tmp < dp[i][j])
                {
                    dp[i][j] = tmp;
                    pre[i][j].x = i-1;
                    pre[i][j].y = j-2;
                }
            }
        }
    printf("%lf\n",dp[n][m]);
    int fx,fy,k=0;
    ans[1].x = n,ans[1].y = m, k = 1;
    fx = pre[n][m].x,fy = pre[n][m].y;
    while (fx && fy)
    {
        k++;
        ans[k].x = fx, ans[k].y = fy;
        fx = pre[ans[k].x][ans[k].y].x;
        fy = pre[ans[k].x][ans[k].y].y;
    }
    for (int i=k;i>0;i--)
    {
        printf("(%d,%d)\n",ans[i].y,ans[i].x);
        if (ans[i-1].x-ans[i].x==2 || ans[i-1].y-ans[i].y==2)
            printf("(%d,%d)\n",ans[i].y+1,ans[i].x+1);
    }
    return 0;
}
