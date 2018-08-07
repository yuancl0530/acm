#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=1e4+7;
using namespace std;
///比较两个串是否相同
///分别比较两个关键字
bool same(int *rank, int idx1, int idx2, int len){
    return rank[idx1]==rank[idx2] && rank[idx1+len]==rank[idx2+len];
}

/// 输入字符串的末尾要补一个 '0' , n是字符串的实际长度+1.



int sa[maxn],sa2[maxn],rk[maxn],cnt[maxn],hgt[maxn];///rk[i]是i的排名，sa[i]是第i小的开头
void SA(int s[], int n, int m){///n是字符串长度+1，m是基数排序的基数

    for(int i=0; i<m; i++) cnt[i]=0;
    for(int i=0; i<n; i++) cnt[rk[i]=s[i]]++;
    for(int i=1; i<m; i++) cnt[i]+=cnt[i-1];
    for(int i=n-1; i>=0; i--) sa[--cnt[rk[i]]]=i;

    for(int len=1; len<n; len*=2){
        ///step-1: 计算（填充） sa2[]
        ///sa2[]: 按第二关键字对后缀排序的结果
        ///对后缀按第二关键字排序这一步可直接用上一次的sa[]数组, 这个过程可形象地理解为将后缀按顺序从一个数组中拿出来放到另一个数组中
        int p=0;
        for(int i=n-len; i<n; i++) sa2[p++]=i;   //第二关键字为空的后缀放在最开头
        ///接着放第二关键字非空的
        ///形象化地理解: 将后缀从一个数组里按顺序拿出来放到另一个数组里
        for(int i=0; i<n; i++)
            if(sa[i]>=len)
                sa2[p++]=sa[i]-len;

        ///step-2 fill sa[], countig sort
        ///计数排序: 每个后缀的第一关键字 (first key) 为上一次针对长度减半的 (部分) 后缀求出来的rank
        for(int i=0; i<m; i++) cnt[i]=0;
        for(int i=0; i<n; i++) cnt[rk[i]]++;
        for(int i=1; i<m; i++) cnt[i]+=cnt[i-1];
        for(int i=n-1; i>=0; i--)
            sa[--cnt[rk[sa2[i]]]]=sa2[i];
        ///step-1 and step-2 together constitute a radix sort

        ///fill rk[]
        swap(rk, sa2);
        rk[sa[0]]=0;
        for(int i=1; i<n; i++)
            ///这里, sa2指向的是旧rank数组
            rk[sa[i]]=rk[sa[i-1]]+!same(sa2, sa[i-1], sa[i], len);

        m=rk[sa[n-1]]+1;
        if(m==n) break;
    }

    ///hgt[i]表示第i小和第i-1小的最长公共前缀
    ///h[i]表示i开头的后缀和它的上一名的最长公共前缀,h[i]=hgt[rk[i]];
    for(int i=0, j, lcp=0; i<n-1; i++){
        lcp?--lcp:0;
        /// 因为在最后加了一个0，最小的一定是最后一个，所以rk[i]>0
        j=sa[rk[i]-1];
        for(; s[j+lcp]==s[i+lcp]; lcp++);
        hgt[rk[i]]=lcp;
    }
}

int a[maxn];
char s[maxn];
int main()
{
    //printf("%d %d %d %d\n",(int)'a',(int)'z',(int)'A',(int)'Z');
    int T,n,m,i,j,k,x,y;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        n=strlen(s);
        for(i=0;i<n;i++) a[i]=s[i]-'A'+1;
        a[n++]=0;
        SA(a,n,59);
        m=0;
        n--;
        for(i=1;i<=n;i++)
        {
            //printf("n=%d sa[%d]=%d hgt[%d]=%d\n",n,i,sa[i],i,hgt[i]);
            m+=n-sa[i]-hgt[i];
        }
        printf("%d\n",m);
    }

}
