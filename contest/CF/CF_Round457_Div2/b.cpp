#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
#define LL long long
const int maxn = 20;
int bit[maxn];
priority_queue<int>Q;
int main()
{
	LL n,k;
	cin >> n >> k;
	int cnt=0;
	int tt=0;
	while (n){
		if (n&1) ++tt;
		bit[cnt++]=n&1;
		n>>=1;
	}
	if (tt>k)
		cout<<"No"<<endl;
	else{
		int t=0;
		for (int i=cnt-1;i>=0;--i)
			if (bit[i]==1) Q.push(i);
		while (tt != k){
			int tmp=Q.top();
			Q.pop();
			Q.push(tmp-1);
			Q.push(tmp-1);
			++tt;
		}
		cout<<"Yes"<<endl;
		for (int i=1;i<=k;++i){
			printf("%d ",Q.top())
			Q.pop();
		}
	}
	return 0;
}
