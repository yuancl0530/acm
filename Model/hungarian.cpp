#include <bits/stdc++.h
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
int num_left;
int num_right;
struct Edge{ int from,to; };
vector<int>G[maxn];
int matching[maxn];
int check[maxn];
bool dfs(int u)
{
	for (int i = 0;i != G[u].size();i++){
		int v = G[u][i];
		if (!check[v]){
			check[v] = true;
			if (matching[v]==-1 || dfs(matching[v])){
				matching[v] = u;
				matching[u] = v;
				return true;
			}
		}
	}
	return false;
}
int hungarian()
{
	int ans = 0;
	Cl(matching,-1);
	for (int i = 0;i < num_left;i++){
		if (matching[i] == -1){
			CL(check);
			if (dfs(i))
				ans++;
		}
	}
	return ans;
}
int main()
{
	return 0;
}
