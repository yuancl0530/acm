#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN (200000 + 10)
#define INF 0x3f3f3f3f
using namespace std;

struct edge{
    int to;
    long long cost;
    edge(int tv = 0, long long tc = 0):
        to(tv), cost(tc){}
};
typedef pair<int ,int> P;
int N, R;
vector<edge> graph[MAXN];
long long dist[MAXN];
long long dist2[MAXN];

void solve(){
    memset(dist, 0x3f,sizeof(dist));
    memset(dist2,0x3f,sizeof(dist2));
    priority_queue<P, vector<P>, greater<P> > Q;
    dist[0] = 0;
    Q.push(P(0, 0));
    while(!Q.empty()){
        P p = Q.top(); Q.pop();
        int v = p.second, d = p.first;
        if(dist2[v] < d) continue;
        for(unsigned i = 0; i < graph[v].size(); i++){
            edge &e = graph[v][i];
            long long d2 = d + e.cost;
            if(dist[e.to] > d2){
                swap(dist[e.to], d2);
                Q.push(P(dist[e.to], e.to));
            }
            if(dist2[e.to] > d2 && dist[v] < d2){
                dist2[e.to] = d2;
                Q.push(P(dist2[e.to], e.to));
            }
        }
    }
    printf("%lld\n", dist2[N-1]);
}
void init()
{
    for(int i=0;i<MAXN;i++)
        graph[i].clear();
}
int main(){
    int A, B;
	long long D;
    int T;
    scanf("%d",&T);
    while(T--){
        init();
        scanf("%d%d", &N, &R);
        for(int i = 0; i < R; i++){
            scanf("%d%d%lld", &A, &B, &D);
            graph[A-1].push_back(edge(B-1, D));
            graph[B-1].push_back(edge(A-1, D));
        }
        solve();
    }
    return 0;
}

