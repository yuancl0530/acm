#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
using namespace std;

#define ll long long
#define mst(a) memset(a, 0, sizeof a)

const int mod = 1e9+7;
const int maxn = 1e5+50;
const int inf = 1e9;

int n, m;

struct node
{
    int x, y;
    int step;
    int d;
    node(int _x, int _y, int _step, int _d): x(_x), y(_y), step(_step), d(_d) {}
};
queue<node> q;
char s[16][16];
bool vis[1 << 16][16][16];
int nextX[16][16], nextY[16][16];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int bfs()
{
    while (!q.empty())
    {
        node t = q.front();
        if (t.d == (1 << m) - 1) return t.step;
        q.pop();
        int x0 = t.x, y0 = t.y;
        for (int i = 0; i < 4; ++i)
        {
            int d = t.d;
            int x = x0 + dx[i], y = y0 + dy[i];
            if (x < 0 || y < 0 || x >= n || y >= n) continue;
            if (s[x][y] == '#' || vis[d][x][y]) continue;
            vis[d][x][y] = true;
            if (s[x][y] >= 'a' && s[x][y] <= 'z' && (d & (1 << s[x][y]-'a')) == 0)
            {
                d = d | (1 << (s[x][y] - 'a'));
                int tmp = x;
                x = nextX[tmp][y];
                y = nextY[tmp][y];
                vis[d][x][y] = true;
            }
            q.push(node(x, y, t.step+1, d));
        }
    }
    return -1;
}

int main()
{
    //freopen("in", "r", stdin);
    while (scanf("%d %d", &n, &m) != EOF)
    {
        mst(vis);
        while (!q.empty()) q.pop();
        for (int i = 0; i < n; ++i) 
            scanf("%s", s[i]);
        for (int i = 0; i < m; ++i) 
        {
            int x1, y1, x2, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            q.push(node(x2-1, y2-1, 0, 1 << i));
            vis[1<<i][x2][y2] = true;
            s[x1-1][y1-1] = i + 'a';
            s[x2-1][y2-1] = i + 'A';
            nextX[x1-1][y1-1] = x2-1;
            nextY[x1-1][y1-1] = y2-1;
        }
        printf("%d\n", bfs());
    }    
    return 0;
}
