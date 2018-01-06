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
const int maxn = 1e6 + 100;
struct Node
{
	int pos;
	int res;
	Node (int p = 1,int r = 1){
		pos = p;
		res = r;
	}
};
int n;
queue<Node>Q;
void print(int pos)
{
	if (!pos) return;
	int n;
	if (pos&1) n=1;
	else n = 0;
	print(pos/2);
	printf("%d",n);
}
void bfs()
{
	while (!Q.empty()){Q.pop();}
	Q.push(Node(1,1));
	while (!Q.empty()){
		int pos = Q.front().pos;
		int res = Q.front().res;
		if (res % n == 0){
			print(pos);
			printf("\n");
			break;
		}
		Q.pop();
		Q.push(Node(2*pos,res*10%n));
		Q.push(Node(2*pos+1,(res*10+1)%n));
	}
}
int main()
{
	while (scanf("%d",&n) != EOF){
		bfs();
	}
	return 0;
}
