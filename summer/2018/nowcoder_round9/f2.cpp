#include <bits/stdc++.h>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define ll long long
const int mod = 1e9 + 7;
const int maxn = 1e5 + 100;
#define N 26
int min(int a,int b)
{
	return a<b? a:b;
}
struct Node
{
	int count,v;
	Node *next[N];
	Node *fail;
	void init(int c=0,Node *f=NULL)
	{
		fail = f;
		count = c;
		v = INF;
		for (int i = 0;i < N;++i) next[i] = NULL;
	}
}node[10*maxn],*Q[10*maxn];
int cnt;
char s[maxn];

void insert(Node *p,char *s)
{
	int n = strlen(s);
	p->v = min(p->v,n);
	for (int i=0;s[i];++i){
		int id = s[i]-'a';
		if (!p->next[id]){
			p->next[id] = &node[cnt++];
			p->next[id]->init();
		}
		p = p->next[id];
		p->v = min(p->v,n-i-1);
	}
	++p->count;
}
void buildAC(Node *root)
{
	int tail = 0;
	int front  = 0;
	Node *p=root;
	p->fail = NULL;
	Q[tail++] = p;
	Node *t;

	while (front < tail){
		p = Q[front++];
		for (int i=0;i<N;++i){
			if (!p->next[i]) continue;
			Q[tail++] =  p->next[i];
			if (p == root) p->next[i]->fail = root;
			else {
				t = p->fail;
				while (t){
					if (t->next[i]){
						p->next[i]->fail = t->next[i];
						break;
					}
					t = t->fail;
				}
				if (!t) p->next[i]->fail = root;
				t = p->next[i];
				t->v = min(t->v,t->fail->v);
			}
		}
	}
}
Node *stk[maxn];
char q[maxn];
void solve(Node *root,char *s)
{
	Node *p = root;
	Node *t;
	int n = strlen(s);
	printf("%d\n",p->v);
	int cur = -1;
	for (int i=0;i < n;++i){
		if (s[i]=='-') --cur;
		else q[++cur] = s[i];
		if (cur < 0) {
			cur = -1;
			printf("%d\n",root->v);
			continue;
		}
		if (cur==0) p = root;
		else p = stk[cur-1];
		int id = q[cur]-'a';
		while (p!=root && p->next[id]==NULL){
			p = p->fail;
		}
		p = p->next[id];
		if (!p) p = root;
		stk[cur] = p;
		int ans = root->v;
		t = p;
		ans = min(t->v,ans);
		printf("%d\n",ans);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	cnt = 0;
	Node * root = &node[cnt++];
	root->init();
	for (int i=0;i<n;++i){
		scanf("%s",s);
		insert(root,s);
	}
	buildAC(root);
	scanf("%s",s);
	solve(root,s);
	return 0;
}
