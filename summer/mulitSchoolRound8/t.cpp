#include<bits/stdc++.h>
using namespace std;

int T,n,m;
char a[220][220];

void solve1()//max = n
{
    for (int Time = 0; Time < n; Time++)
    {
        for (int i=0;i<m/2;i++) printf("(");
        for (int i=m/2;i<m;i++) printf(")");
        printf("\n");
    }
}

void solve2()//max = m
{
    for (int Time = 0; Time < n; Time++)
    {
        char c = (Time & 1)? ')' : '(' ;
        for (int i = 0; i < m; i++) printf("%c",c);
        printf("\n");
    }
}

void solve()
{
    if (m > n)
    {
        for (int j = 0; j < m; j++) a[0][j] = '(';
        for (int i = 1; i < n-1; i++)
        {
            if (i & 1)
            {
                for (int j = 0; j < m/2; j++) a[i][j] = ')';
                for (int j = m/2; j < m; j++) a[i][j] = '(';
            }
            else
            {
                for (int j = 0; j < m/2; j++) a[i][j] = '(';
                for (int j = m/2; j < m; j++) a[i][j] = ')';
            }
        }
        for (int j = 0; j < m; j++) a[n-1][j] = ')';
    }
    else
    {
        for (int i = 0; i < n; i++) a[i][0] = '(';
        for (int j = 1; j < m-1; j++)
        {
            if (j & 1)
            {
                for (int i = 0; i < n/2; i++) a[i][j] = ')';
                for (int i = n/2; i < n; i++) a[i][j] = '(';
            }
            else
            {
                for (int i = 0; i < n/2; i++) a[i][j] = '(';
                for (int i = n/2; i < n; i++) a[i][j] = ')';
            }
        }
        for (int i = 0; i < n; i++) a[i][m-1] = ')';
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) printf("%c",a[i][j]);
        printf("\n");
    }
}


int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d %d",&n,&m);
        if (n & 1) solve1();
        else
            if (m & 1) solve2();
            else
                solve();
    }
    return 0;
}
