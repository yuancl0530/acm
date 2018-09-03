/*********************************
Date: Tue Aug 21 19:21:00 CST 2018
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
const int maxn = 1e5 + 100;
struct Node
{
	Node* next[2];
	int v;
}node[50*maxn];
int id = 0;
Node *createNode()
{
	Node *t = &node[id++];
	t->v = 0;
	t->next[0] = t->next[1] = NULL;
	return t;
}
void insert(Node *root, ll v)
{
	Node *p = root;
	for (int i = 40;i >= 0;--i){
		bool k = v>>i & 1;
		if (!p->next[k]) p->next[k] = createNode();
		p = p->next[k];
		++p->v;
	}
}
void sub(Node *root,ll v)
{
	Node *p = root;
	for (int i = 40;i >= 0;--i){
		bool k = v>>i & 1;
		p = p->next[k];
		--p->v;
	}
}
ll query(Node *root,ll v)
{
	Node *p = root;
	ll ans = 0;
	for (int i = 40;i >= 0;--i){
		bool k = !(v>>i & 1);
		if (p->next[k] && p->next[k]->v > 0){
			p = p->next[k];
			ans |= 1ll<<i;
		}
		else p = p->next[!k];
	}
	return ans;
}
ll a[maxn],s[maxn];
int main()
{
	int n;
	cin >> n;
	a[0] = a[n+1] = 0;
	for (int i = 1;i <= n;++i) cin >> a[i];
	id = 0;
	Node *root = createNode();
	insert(root,s[n+1]);
	for (int i = n;i >= 0;--i){
		s[i] = s[i+1] ^ a[i];
		insert(root,s[i]);
	}
	ll pre = 0;
	ll ans = 0;
	for (int i = 0;i <= n;++i){
		pre ^= a[i];
		sub(root,s[i]);
		ans = max(ans,query(root,pre));
	}
	cout << ans << endl;
	return 0;
}
