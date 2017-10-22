#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;
int n,m;
const int maxn=100;
const int maxm=100;
double d[maxn][maxm];
string str;
int main()
{
	while (getline(cin,str)){
		++n;
		m=1;
		//cout<<str<<endl;
		stringstream ss;
		ss<<str;
		while (ss>>d[n][m])
			++m;
	}
	--m;
	cout<<n<<" "<<m<<endl;
	for (int i=1;i<=n;++i){
		for (int j=1;j<=m;j++)
			cout<<d[i][j]<<" ";
		cout<<endl;
	}
}
