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
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
const int MOD = 1e9 + 7;
const int maxn = 1e6 + 100;
int Stack[maxn];
int Top,Bot;
int zero[maxn];
int Left,Right;
const int Mid = maxn/2;
void Init()
{
	Left = Right = Mid;
	Top = Bot = Mid;
	Stack[Top] = -1;
	zero[Left] = -1;
}
void reserve()
{
	swap(Top,Bot);
}
void push(int a)
{
	if (Top >= Bot){
		if (Stack[Top] == -1){
			Stack[Top] = a;
		}
		else{
			Stack[++Top] = a;
		}
		if (Stack[Top] == 0){
			if (zero[Left] == -1){
				zero[Left] = Top;
			}
			else{
				zero[++Right] = Top;
			}
		}
	}
	else{
		if (Stack[Top] == -1){
			Stack[Top] = a;
		}
		else{
			Stack[--Top] = a;
		}
		if (Stack[Top] == 0){
			if (zero[Left] == -1){
				zero[Left] = Top;
			}
			else{
				zero[--Left] = Top;
			}
		}
	}
}
void pop()
{
	int t  = Stack[Top];
	if (Top == Bot){
		Stack[Top] = -1;
	}
	else if (Top > Bot){
		--Top;
	}
	else{
		++Top;
	}
	if (t == 0){
		if (Left == Right){
			zero[Left] = -1;
		}
		else{
			if (Top > Bot){
				Right--;
			}
			else{
				Left++;
			}
		}
	}
}
int query()
{
	if (Top == Bot && Stack[Top] == -1){
		return -1;
	}
	if (Stack[Bot] == 0){
		if (Top == Bot)
			return 0;
		else
			return 1;
	}
	else{
		if (Top == Bot){
			return 1;
		}
		if (Top > Bot){
			int t = zero[Left];
			if (t==-1){
				int k = Top-Bot+1;
				if (k&1)
					return 1;
				else
					return 0;
			}
			int k = zero[Left] - Bot;
			if (t == Top){
				if (k&1)
					return 1;
				return 0;
			}
			if (k&1)
				return 0;
			else
				return 1;
		}
		else{
			int t = zero[Right];
			if (t==-1){
				int k = Bot - Top+1;
				if (k&1)
					return 1;
				else
					return 0;
			}
			int k = Bot - zero[Right];
			if (t==Top){
				if (k&1)
					return 1;
				return 0;
			}
			if (k&1)
				return 0;
			else
				return 1;
		}
	}
}
char op[30];
int main()
{
	int T,n,t=0;
	scanf("%d",&T);
	while (T--){
		Init();
		printf("Case #%d:\n",++t);
		scanf("%d",&n);
		for (int i = 0;i < n;i++){
			scanf("%s",op);
			if (op[0] == 'P' && op[1] == 'U'){
				int a;
				scanf("%d",&a);
				push(a);
			}
			else if (op[0] == 'P')
				pop();
			else if (op[0] == 'Q'){
				int t = query();
				if (t == -1)
					printf("Invalid.\n");
				else
					printf("%d\n",t);
			}
			else
				reserve();
		}
	}
	return 0;
}
