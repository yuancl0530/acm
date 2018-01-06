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
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 200 + 100;
struct Node
{
	int v;
	int left;
	int right;
	int cal(){
		right = v%10 + v/10%10 + v/100%10;
		int t = v/1000;
		left = t%10 + t/10%10 + t/100%10;
	}
}node[maxn];
int n,m;
int matching[maxn];
bool vs[maxn];
vector<int>edge[maxn];
vector<int>::iterator it;
bool dfs(int u)
{
	for (int i = 0;i< edge[u].size();++i){
		int t = edge[u][i];
		if (!vs[t]){
			vs[t] = true;
			if (matching[t] == -1 || dfs(matching[t])){
				matching[t] = u;
				matching[u] = t;
			//	cout <<u<<" "<<t<<endl;
				return true;
			}
		}
	}
	return false;
}
int hungarian()
{
	int ret = 0;
	Cl(matching,-1);
	for (int i = 0;i < n;i++){
		if (matching[i] == -1){
			CL(vs);
			if (dfs(i)){
				ret++;
			}
		}
	}
	return ret;
}
void print()
{
	for (int i = 0;i < n;i++){
			if (matching[i] != -1){
			int t = matching[i];
			if (node[i].left == node[t].right){
				printf("AT %d %d\n",node[i].v,node[t].v);
			}
			else{
				printf("TA %d %d\n",node[t].v,node[i].v);
			}
		}
	
	}
}
int main()
{
	freopen("INPUT.TXT","r",stdin);
	freopen("OUTPUT.TXT","w",stdout);
	while (scanf("%d%d",&n,&m) != EOF){
		for (int i = 0;i < n + m;i++){
			edge[i].clear();
		}
		for (int i = 0;i < n+m;i++){
			scanf("%d",&node[i].v);
			node[i].cal();
		}
		for (int i = 0;i < n;i++){
			for (int j = n;j < n + m;j++){
				if (node[i].left == node[j].right ||
					node[i].right == node[j].left){
					edge[i].push_back(j);
					edge[j].push_back(i);
				}
			}
		}
		/*for (int i = 0;i < n+m;i++){
			cout << i <<":";
		for (it = edge[i].begin();it != edge[i].end();it++){
		//	for (int j = 0;j < edge[i].size();j++){
				cout <<*it<<" ";
			}
			cout << endl;
		}*/
		int ans = hungarian();

		printf("%d\n",ans);
		print();

	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}
