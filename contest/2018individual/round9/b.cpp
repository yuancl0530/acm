#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int Max = 1e6 + 100;
int n,m;
ll ans = 0;
struct Edge
{
    int u,v,w;
	int use;
}a[Max];
int father[Max];
vector<int>G[Max];
int Find( int x )
{
    if (father[x] == x) return x;
    else
        return father[x] = Find( father[x]);
}
bool cmp(Edge a,Edge b)
{
    return a.w < b.w;
}
void Kruskal()
{
    for (int i = 0;i < m;i++){
        int n1 = Find(a[i].u);
        int n2 = Find(a[i].v);
        if(n1 != n2){
            father[n1] = father[n2];
			ans += a[i].w;
			a[i].use = 1;
        }
    }
    return ;

}
bool vs[Max];
int cnt[Max];
double res;
int dfs(int u)
{
	vs[u] = true;
	for (int i = 0;i < G[u].size();++i){
		int v = G[u][i];
		if (vs[v]) continue;
		//cout << u<<" "<<v<<endl;
		++cnt[u];
		cnt[u] += dfs(v);
	}
	return cnt[u];
}
int main()
{
	int T;
	scanf("%d",&T);
    while(T--){
		scanf("%d%d",&n,&m);
		ans = 0;
        for (int i = 1 ;i <= n;i++){
            father[i] = i;
			G[i].clear();
			cnt[i]  = 0;
			vs[i] = 0;
		}
        int u,v,w;
        for (int i = 0; i < m;i++){
            scanf("%d%d%d",&u,&v,&w);
            a[i].u=u;
            a[i].v=v;
            a[i].w=w;
			a[i].use = 0;
        }
        sort(a,a+m,cmp);
        Kruskal();
		for (int i = 0;i < m;++i){
			if (a[i].use==0) continue;
			int u = a[i].u;
			int v = a[i].v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		res = 0;
		dfs(1);
		for (int i = 0;i < m;++i){
			if (a[i].use ==0 ) continue;
			int u = a[i].u;
			int v = a[i].v;
			int tb = min(cnt[u],cnt[v]);
			//cout<<a[i].u<<" "<<a[i].v<<" "<<(tb+1)*(n-tb-1)<<endl;;
			res += (double)a[i].w*(tb+1)*(n-tb-1);
		}
		//cout<<res<<endl;
		res = res/((ll)n*(n-1))*2;
        printf("%lld %.2lf\n",ans,res);
    }
    return 0;
}


