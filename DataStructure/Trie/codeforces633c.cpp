/*********************************
Date: Wed Aug 22 09:33:06 CST 2018
Author: ycl
*********************************/
#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,(b),sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x3f3f3f3f
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e6 + 100;
struct Node
{
	Node *next[26];
	int id;
}node[maxn];
int id=0,cnt=0,ans[maxn];
Node *root = &node[id++];
string s[maxn],t;
void insert(string s,int no)
{
	Node *p = root;
	for (int i = s.length()-1;i >=0;--i){
		int k = tolower(s[i]) - 'a';
		if (!p->next[k]) p->next[k] = &node[id++];
		p = p->next[k];
	}
	p->id = no;
}
void dfs(int u=0,int d=0)
{
	if (cnt) return ;
	if (u == t.length()) { cnt = d; return ; }
	Node *p = root;
	for (int i = u;!cnt && i < t.length();++i){
		int k = t[i] - 'a';
		if (!p->next[k]) return;
		p = p->next[k];
		if (p->id ) {
			ans[d] = p->id;
			dfs(i+1,d+1);
		}
	}
}
int main()
{
	int n,m;
	cin >> n >> t >> m;
	for (int i = 1;i <= m;++i) {
		cin >> s[i];
		insert(s[i],i);
	}
	dfs();
	for (int i = 0;i < cnt;++i)
		cout << s[ans[i]] <<" ";
	cout<<endl;
	return 0;
}
