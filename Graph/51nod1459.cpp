#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <list>
#include <set>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7f7f7f7f
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e3 + 100;
int dis[maxn][maxn];
vector<int>V[maxn];
int n,m,start,end;
struct Node
{
	int i;
	int dis;
	int s;
	int score;
	friend bool operator < (Node a,Node b){
		if (a.dis == b.dis)
			return a.s < b.s;
		return a.dis > b.dis;
	}

}node[maxn];
priority_queue<Node>Q;
void dijkstra(int s)
{
	while (!Q.empty()) Q.pop();
	int now = s;
	node[s].dis = 0;
	node[s].score = node[s].s;
	Q.push(node[s]);
	while (!Q.empty()){
		int now = Q.top().i;
		Q.pop();
		vector<int>::iterator it;
		for (it = V[now].begin();it != V[now].end();it++){
			if (node[now].dis + dis[*it][now] < node[*it].dis){
				node[*it].dis = node[now].dis + dis[*it][now];
				node[*it].score = node[now].score + node[*it].s;
				Q.push(node[*it]);
			}
			else if (node[*it].dis == node[now].dis + dis[*it][now]){
				node[*it].score = max(node[*it].score,node[*it].s + node[now].score);
				Q.push(node[*it]);
			}
		}
	}
}
int main()
{
	while (scanf("%d%d%d%d",&n,&m,&start,&end) != EOF){
		Cl(node,0x7f);
		for (int i = 0;i < n;i++){
			scanf("%d",&node[i].s);
			node[i].i = i;
			V[i].clear();
		}
		int x,y,z;
		while (m--){
			scanf("%d%d%d",&x,&y,&z);
			dis[x][y] = z;
			dis[y][x] = z;
			V[x].push_back(y);
			V[y].push_back(x);
		}
		dijkstra(start);
		printf("%d %d\n",node[end].dis,node[end].score);
	}
	return 0;
}
