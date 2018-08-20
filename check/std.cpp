/*************************************************************************
    > File Name: A.cpp
    > Author: acvcla
    > QQ:
    > Mail: acvcla@gmail.com 
    > Created Time: 2014年11月17日 星期一 23时34分13秒
 ************************************************************************/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<cstdlib>
#include<ctime>
#include<set>
#include<math.h>
using namespace std;
typedef long long LL;
typedef pair<int,int>pii;
const int maxn = 3e5 + 10;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
int siz[maxn],rev[maxn],pre[maxn],ch[maxn][2],key[maxn],ans[maxn];
int tot,root,n;
inline void newnode(int &x,int fa,int k){
	x=++tot;
	pre[x]=fa;
	siz[x]=1;
	key[x]=k;
	ch[x][0]=ch[x][1]=rev[x]=0;
}
inline void Modify(int x){
	if(!x)return;
	rev[x]^=1;
}
inline void push_down(int x){
	if(x&&rev[x]){
		swap(ch[x][0],ch[x][1]);
		Modify(ch[x][0]);
		Modify(ch[x][1]);
		Modify(x);
	}
}
inline void push_up(int x){
	if(!x)return ;
	siz[x]=siz[ch[x][0]]+siz[ch[x][1]]+1;
}
void built(int &x,int L,int R,int fa){
	if(L>R)return;
	int M=(L+R)>>1;
	newnode(x,fa,M);
	built(ch[x][0],L,M-1,x);
	built(ch[x][1],M+1,R,x);
	push_up(x);
}
void Rotate(int x,int kind){
	int y=pre[x];
	push_down(y);
	push_down(x);
 
	ch[y][!kind]=ch[x][kind];
	pre[ch[x][kind]]=y;
	ch[x][kind]=y;
 
	if(pre[y])ch[pre[y]][ch[pre[y]][1]==y]=x;
	pre[x]=pre[y];
	pre[y]=x;
 
	push_up(y);
	push_up(x);
}
void Splay(int x,int goal){
	while(pre[x]!=goal){
		if(pre[pre[x]]==goal){
			Rotate(x,ch[pre[x]][0]==x);
		}else{
			int y=pre[x];
			int kind=(ch[pre[y]][0]==y);
			if(ch[y][kind]==x){
				Rotate(x,!kind);
				Rotate(x,kind);
			}else{
				Rotate(y,kind);
				Rotate(x,kind);
			}
		}
	}
	if(goal==0)root=x;
}
int Get_kth(int x,int k){
	push_down(x);
	int tz=siz[ch[x][0]]+1;
	if(tz==k)return x;
	if(tz>k)return Get_kth(ch[x][0],k);
	return Get_kth(ch[x][1],k-tz);
}
void init(int n){
	root=tot=siz[0]=pre[0]=ch[0][0]=ch[0][1]=rev[0]=0;
	newnode(root,0,-1);
	newnode(ch[root][1],root,n+1);
	built(ch[ch[root][1]][0],1,n,ch[root][1]);
	push_up(ch[root][1]);
	push_up(root);
}
int Get_max(int x){
	push_down(x);
	while(ch[x][1]){
		x=ch[x][1];
		push_down(x);
	}
	return x;
}
void merge(int root1,int root2)/*root2接到root1右子树，要求root1无右子树*/
{
	ch[root1][1]=root2;
	pre[root2]=root1;
}
int __;
void travel(int x){
	if(!x)return;
	push_down(x);
	travel(ch[x][0]);
	ans[__++]=key[x];
	travel(ch[x][1]);
}
int main(){
		int n,m;
		while(~scanf("%d%d",&n,&m)){
			if(n<0&&m<0)return 0;
			init(n);
			char op[10];
			int L,R,C;
			while(m--){
				scanf("%s%d%d",op,&L,&R);
				if(op[0]=='F'){
					Splay(Get_kth(root,L),0);
					Splay(Get_kth(root,R+2),root);
					Modify(ch[ch[root][1]][0]);
				}else{
					scanf("%d",&C);
					Splay(Get_kth(root,L),0);
					Splay(Get_kth(root,R+2),root);
					int root1=ch[ch[root][1]][0];/*删除区间[L,R]*/
					ch[ch[root][1]][0]=0;
					push_up(ch[root][1]);
					push_up(root);
					Splay(Get_kth(root,C+1),0);/*先分裂区间C两边，插入区间[L,R]，然后合并*/
					int root2=ch[root][1];
					merge(root,root1);
					push_up(root);
					Splay(Get_max(root),0);
					merge(root,root2);
					push_up(root);
				}
			}
			__=0;
			travel(root);
			rep(i,1,n)printf("%d ",ans[i]);
			printf("\n");
		}
		return 0;
}
