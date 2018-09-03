#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <cctype>
using namespace std;
#define CL(a) memset(a,0,sizeof(a));
#define LL long long
const int INF= 0x7fffffff;
const int maxn = 2e5 + 10;
struct Node
{
    int left;
    int right;
    int value;
};
int a[maxn];

class tree
{
private:
	Node node[4 * maxn];
public:
    tree()
    {
        memset(node,0,sizeof node);
    }
    void clea(){memset(node,0,sizeof node);}
    void bulid(int left,int right,int pos = 1)
    {
        node[pos].left = left;
        node[pos].right = right;
        if (left == right){
            node[pos].value = a[left];
        }else{
            bulid(left,(left+right)/2,2*pos);
            bulid((left+right)/2+1,right,2*pos+1);
            node[pos].value = max(node[2*pos].value , node[2*pos+1].value);
        }
    }
    int query(int left,int right,int pos= 1)
    {
        if (right < node[pos].left || left > node[pos].right)
            return -1;
        if (left <= node[pos].left && right >= node[pos].right)
            return node[pos].value;
        int l,r;
        l = query(left,right,2*pos);
        r = query(left,right,2*pos+1);
        return max(l,r);
    }
    int update(int val,int index,int pos = 1)
    {
        if (index == node[pos].left && index == node[pos].right)
            return node[pos].value = a[index] = val;
        if (index < node[pos].left || index > node[pos].right)
            return node[pos].value;
        int l = update(val,index,2*pos);
        int r = update(val,index,2*pos+1);
        return node[pos].value = max(l,r);
    }
};

int main()
{
   int n,m;
    char c;
    int x,y;
    tree *T = new tree;
    while (scanf("%d%d",&n,&m) != EOF){
        memset(a,0,sizeof a);
        T->clea();
        for (int i = 1;i <= n;i++)
            scanf("%d",&a[i]);
        T->bulid(1,n);
        for (int i = 0;i < m;i++){
            getchar();//消除行尾回车符
            scanf("%c%d%d",&c,&x,&y);
            if (c == 'Q')
                printf("%d\n",T->query(x,y));
            else{
                T->update(y,x);
            }
        }
    }
    return 0;
}
