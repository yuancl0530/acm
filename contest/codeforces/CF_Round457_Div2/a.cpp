#include <iostream>

using namespace std;
bool check(int h,int m)
{
	if (h%10 == 7)
		return true;
	if (m%10 == 7)
		return true;
	return false;
}

int main()
{
	int h,m,x;
	cin>>x;
	cin>>h>>m;
	int ans=0;
	while (!check(h,m)){
		++ans;
		if (m-x<0){
			if (h==0)
				h=23;
			else
				--h;
		}
		m = (m-x+60)%60;
	}
	cout<<ans<<endl;
	return 0;
}
