//高精度乘法 
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
const int maxn = 300+10;
char a[maxn],b[maxn];
int c[maxn],d[maxn];
int x[maxn],y[maxn];
void addnum(int* a,int* b){
	for(int i=0;i<maxn;i++)
	{
		a[i]+=b[i];	
	} 
} 
int jinwei(int *a){
	int i;
	int maxx;
	for(i=305;i>0;i--){
		if(a[i]){
			maxx = i;  break;
		}
	}
	for(int i=0;;i++){
		if(i>maxx&&a[i]==0){
			return i-1;
		}
		if(a[i]>=10){
			a[i+1] += a[i]/10;
			a[i] %= 10;
		} 
		
	} 
	return maxx;
}
void out(int *a,int maxsub)
{
	for(int i=maxsub;i>=0;i--)
		printf("%d",a[i]);
	printf("\n");
}
int main()
{
	while(scanf("%s",a)!=EOF){
		scanf("%s",b);
		int i,j,l;
		int la = strlen(a);
		int lb = strlen(b);
		CL(x);
		CL(y);
		for(i=0;i<la;i++)           //把字符串转化为整型数组 
			x[la-i-1] = a[i] - '0';
		for(i=0;i<lb;i++)
			y[lb-i-1] = b[i] - '0';
		memset(c,0,sizeof(c));
		for(int i=0;i<lb;i++){      //模拟竖式 
			memset(d,0,sizeof(d));
			for(int j=0;j<la;j++)
			{
				d[j+i] = x[j] * y[i]; 
			}
			addnum(c,d);
		}
		int maxsub = jinwei(c);   //统一进位，并返回最高位下标 
		out(c,maxsub);
    }
	return 0;	
} 
