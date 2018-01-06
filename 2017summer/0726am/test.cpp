#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#include<set>
#include<stdio.h>
#include<map>
#include<queue>
#include<stdio.h>
using namespace std;
#define LL long long
#define CLR(a,b) memset(a,b,sizeof(b))
#define INF 0x3f3f3f3f
#define MAX 100010
#define Mod 1000000007
struct node{
	int c;
    int num[MAX];
}s[30];

int change[30];
int spmod(int x,int y)
{
    int ans=1;
    while(y!=0){
        if(x&1==1)
            ans=ans*x%Mod;
        x=x*x%Mod;
        y>>=1;
    }
    return ans;
}
bool cmp(node a,node b)
{
    for(int i=MAX-1;i>=1;i--){
        if(a.num[i] != b.num[i] )
            return a.num[i] > b.num[i];
        else
            continue;
    }
    return 0;
}
int main()
{
    int n;
    char temp[MAX];
    while(scanf("%d",&n)!=EOF){
		for (int i = 0;i < 26;i++){
			s[i].c = i;
		}
        while(n--){
            scanf("%s",temp);
            int len=strlen(temp);
            for(int i=len-1;i>=0;i--){
                s[temp[i]-'a'].num[len-i]++;
            }
        }
        for(int i=0;i<26;i++){
            for(int j=1;j<MAX;j++){
                s[i].num[j+1]+=s[i].num[j]/26;
                s[i].num[j]%=26;
            }
        }
        sort(s,s+26,cmp);

        for (int i = 0;i < 26;i++)
			printf("%c ",s[i].c + 'a');


    }
    return 0;
}
