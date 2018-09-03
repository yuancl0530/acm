/*********************************
Date: Tue Aug 21 19:56:32 CST 2018
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
	Node *next[2];
}node[50*maxn],*root[maxn];
int id = 0;
Node *createNode()
{
	Node *t = &node[id++];
	t->next[0] = t->next[2] = NULL;
	return t;
}
Node* insert(Node *p,ll v)
{
	Node *root = createNode();
	Node *t = root;
	*t = *p;
	for (int i = 40;i >= 0;--i){
		bool k = v>>i & 1;
		t->next[k] = createNode();
		if (p && p->next[k]) *t->next[k] = *p->next[k];
		else p = NULL;
		if (p) p = p->next[k];
		t = t->next[k];
	}
	return root;
}
ll query(Node *root,ll v)
{
	ll ans = 0;
	Node *p = root;
	for (int i = 40;i >= 0;--i){
		bool k = !(v>>i & 1);
		if (p->next[k]) {
			p = p->next[k];
			ans |= 1ll<<i;
		}
		else p = p->next[!k];
	}
	return ans;
}
ll a[maxn];
int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;++i) cin >> a[i];
	a[0] = a[n+1] = 0;
	ll p = 0;
	root[n+2] = createNode();
	for (int i = n+1;i >= 0;--i){
		p ^= a[i];
		root[i] = insert(root[i+1],p);
	}
	p = 0;
	ll ans = 0;
	for (int i = 0;i <= n;++i){
		p ^= a[i];
		ans = max(ans,query(root[i+1],p));
	}
	cout << ans << endl;
	return 0;
}
