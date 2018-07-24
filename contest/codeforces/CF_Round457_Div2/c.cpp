#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int p = 1e5+19;
	cout<<p<<" "<<p<<endl;
	for (int i=2;i<n;++i)
		printf("%d %d 1\n",i-1,i);
	printf("%d %d %d\n",n-1,n,p-n+2);
	int t = n-1;
	for (int i=1;i<=n;++i){
		if (t == m)break;
		for (int j=i+2;j<=n;++j){
			printf("%d %d %d\n",i,j,p);
			++t;
			if (t==m)break;
		}
	}

	return 0;
}
