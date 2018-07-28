#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=100100;
const int MAXL=120;

int x,n,l,r,df;
int top[MAXN],Rank[MAXN],temp[MAXN],sa[MAXN],height[MAXN];
int s[MAXN],belong[MAXN];
char s1[MAXL];
bool v[MAXL];

void Make()
{
     int i,j,len,m;
     m=n<256?256:n;
     memset(top,0,m*sizeof(int));
     for (i=0;i<n;++i) ++top[Rank[i]=s[i]&0xff];
     for (i=1;i<m;++i) top[i]+=top[i-1];
     for (i=0;i<n;++i) sa[--top[Rank[i]]]=i;
     for (len=1;len<n;len<<=1)
     {
         for (i=0;i<n;++i)
         {
             j=sa[i]-len;
             if (j<0) j+=n;
             temp[top[Rank[j]]++]=j;
         }
         sa[temp[top[0]=0]]=j=0;
         for (i=1;i<n;++i)
         {
             if (Rank[temp[i]]!=Rank[temp[i-1]] ||
                Rank[temp[i]+len]!=Rank[temp[i-1]+len])
                top[++j]=i;
             sa[temp[i]]=j;
         }
         memcpy(Rank,sa,n*sizeof(int));
         memcpy(sa,temp,n*sizeof(int));
         if (j>=n-1) break;
     }
}
     
void Lcp()
{
     int i,j,k;
     for (j=Rank[height[i=k=0]=0];i<n-1;++i,++k)
         while (k>=0 && s[i]!=s[sa[j-1]+k])
               height[j]=k--,j=Rank[sa[j]+1];
}

bool Judge(int limit)
{
     int i,d=0;
     memset(v,0,sizeof(v));
     v[0]=1;
     if (!v[belong[sa[0]]]) ++d;
     v[belong[sa[0]]]=1;
     for (int i=1;i<n;++i)
     {
         if (height[i]<limit)
         {
                             d=0;
                             memset(v,0,sizeof(v));
                             v[0]=1;
         }
         if (!v[belong[sa[i]]]) ++d;
         if (d>x/2) return 1;
         v[belong[sa[i]]]=1;
     }
     return 0;
}

void PRINT(int limit)
{
     int i,tmp,d=0;
     memset(v,0,sizeof(v));
     v[0]=1;
     if (!v[belong[sa[0]]]) ++d;
     v[belong[sa[0]]]=1;
     for (i=1;i<n;++i)
     {
         if (height[i]<limit)
         {
                             if (d>x/2)
                             {
                                       for (int j=sa[i-1];j<sa[i-1]+limit;++j) printf("%c",s[j]-5);
                                       printf("\n");
                             }
                             d=0;
                             memset(v,0,sizeof(v));
                             v[0]=1;
         }
         if (!v[belong[sa[i]]]) ++d;
         v[belong[sa[i]]]=1;
     }
     if (d>x/2)
     {
               for (int j=sa[i-1];j<sa[i-1]+limit;++j) printf("%c",s[j]-5);
               printf("\n");
     }
}

void Solve()
{
     int ans=-1,mid;l=1;
     while (l<=r)
     {
           mid=(l+r)/2;
           if (Judge(mid)) ans=mid,l=mid+1; else r=mid-1;
     }
     if (ans==-1) printf("?\n"); else PRINT(ans);
}

int main()
{
    int f=0,len;
    while (scanf("%d",&x),x)
    {
          if (f) printf("\n"); else f=1;
          n=r=df=0;
          for (int i=1;i<=x;++i)
          {
              scanf("%s",s1);
              len=strlen(s1);
              if (r<len) r=len;
              for (int j=0;j<len;++j) s[n+j]=(int)s1[j]+5,belong[n+j]=i;
              s[n+len]=++df,belong[n+len]=0;
              n=n+len+1;
          }
          s[n-1]=0;
          if (x==1) {printf("%s\n",s1);continue;}
          Make();
          Lcp();
          //for (int i=0;i<n;++i) printf("%d ",s[i]);
          //printf("\n");
          Solve();
    }
    return 0;
}
