#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 1e5+50;
int n;
vector<int> vecX[maxn], vecY[maxn];
map<int, int> idX, idY;
set<pair<int, int> > vis;
int cntX, cntY;
int x[maxn], y[maxn];

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        int ans = 0;
        idX.clear();
        idY.clear();
        vis.clear();
        for (int i = 0; i < n; ++i)
        {
            vecX[i].clear();
            vecY[i].clear();
        }
        cntX = 1;
        cntY = 1;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d %d", &x[i], &y[i]);
            vis.insert(make_pair(x[i], y[i]));
            if (!idX[x[i]]) idX[x[i]] = cntX++;
            if (!idY[y[i]]) idY[y[i]] = cntY++;
            vecX[idX[x[i]]].push_back(y[i]);
            vecY[idY[y[i]]].push_back(x[i]);
        }
        for (int i = 1; i < cntX; ++i)
            sort(vecX[i].begin(), vecX[i].end());
        for (int i = 1; i < cntY; ++i)
            sort(vecY[i].begin(), vecY[i].end());
        for (int i = 0; i < n; ++i)
        {
            int x0 = idX[x[i]];
            int y0 = idY[y[i]];
            vector<int>::iterator itX = upper_bound(vecX[x0].begin(), vecX[x0].end(), y0);
            vector<int>::iterator itY = upper_bound(vecY[y0].begin(), vecY[y0].end(), x0);
            while (itX != vecX[x0].end() && itY != vecY[y0].end())
            {
                int a = *itX - y[i];
                int b = *itY - x[i];
				
                if (a == b)
                {
                    if (vis.count(make_pair(x[i]+a, y[i]+a)))
                        ans = max(a, ans);
                    itX++;
                    itY++;
                }
                else if (a < b)
                {
                    while (a < b)
                    {
                        itX++;
                        if (itX == vecX[x0].end()) break;
                        a = *itX - y[i];
                    }
                }
                else
                {
                    while (a > b)
                    {
                        itY++;
                        if (itY == vecY[y0].end()) break;
                        b = *itY - x[i];
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
