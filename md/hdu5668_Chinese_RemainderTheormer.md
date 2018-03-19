
# HDU5668(中国剩余定理)  
## 涉及知识点  
`欧几里德算法` `扩展欧几里德算法` `中国剩余定理`
## 链接  
[hdu5668](http://acm.hdu.edu.cn/showproblem.php?pid=5668) http://acm.hdu.edu.cn/showproblem.php?pid=5668 

## 题意  
约瑟夫环问题  
n个人围成一圈，标号1～n，从1开始计数，第k个人出列，下一个人再次从1计数，第k个人出列直到所有人离开圈  
给定用a[i]表示编号为i的人，出列的次序，求最小的k满足以上出列序列，如果不存在输出"Creation August is a SB!"  


## 解题思路  
中国剩余定理典型题目，但模数存在不互质的情况，需要进一步处理  
### 中国剩余定理  
中国剩余定理给出了以下的一元线性同余方程组
$$
\begin{cases}
x \equiv a_1 (\mod m_1)\\  
x \equiv a_2 (\mod m_2)\\  
\vdots \\
x \equiv a_n (\mod m_n)\\
\end{cases}  
$$
**其中$m_1,m_2 \cdots m_n$两两互质**  
  
  
推倒过程  
1.设$M = m_1*m_2* \cdots * m_i$   
2.设$M_i = M/m_i$  
3.通解  
$x=a_1*M_i^{-1}*M_i+a_2*M_i^{-1}\cdots a_i*M_i^{-a}*M_i + k*M$ (其中$M_i^{-1}$为$M_i$模$m_i$的逆元)  
对于任意$m_i$,$x\%m_i=a_i$

### 不互质的情况  
$$
\begin{cases}
x \equiv a_1 (\mod n_1)\\
x \equiv a_2 (\mod n_2)\\
\end{cases} 
$$

$$
x = n_1k_1+a_1 \cdots (1) \\
x = n_2k_2+a_1 \cdots (2)
$$
(1)-(2)得  $$n_1k_1-n_2k_2=a_2-a_1$$  
$$n_1k_1 \equiv (a_2-a_1) (\mod n_2)$$
有解的话必然要满足$gcd(n_1,n_2)|(a_2-a_1)$,令$c=a_2-a_1$ 
$$
\frac{n_1}{d}k_1 \equiv \frac{c}{d}(\mod \frac{n_2}{d})
$$
$$
k_1 \equiv \frac{c}{d}*(\frac{n_1}{d})^{-1}(\mod \frac{n_2}{d})
$$
$$
k_1 = \frac{c}{d}*(\frac{n_1}{d})^{-1} + t* \frac{n_2}{d}
$$
带入(1)式得
$$
x= n_1*(\frac{c}{d}*(\frac{n_1}{d})^{-1} + t* \frac{n_2}{d})+a_1
$$
$$
x \equiv n_1*(\frac{c}{d}*(\frac{n_1}{d})^{-1} )+a_1 (\mod \frac{n_1n_2}{d})
$$
$$
x \equiv n_1*(\frac{c}{d}*(\frac{n_1}{d})^{-1} )+a_1 (\mod \frac{n_1n_2}{d})
$$
因此
$$
a_3 = n_1*(\frac{c}{d}*(\frac{n_1}{d})^{-1} )+a_1
$$
$$
n_3=\frac{n_1n_2}{d}
$$
(1)(2)式可以等价转化成
$$
x \equiv a_3 (\mod n_3)
$$

## 解题代码
```
/*********************************
Date: Tue Mar 13 22:00:01 CST 2018
Author: ycl
*********************************/
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
#include <set>
#include <sstream>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define MP(a,b) make_pair(a,b)
#define INF 0x7fffffff
#define LL long long
#define N 401
const int mod = 1e9 + 7;
const int maxn = 1e3+10;
int a[maxn];
int b[maxn];
int n;
LL exgcd(LL a,LL b,LL &x,LL &y)
{
	if (b==0){
		x = 1;
		y = 0;
		return a;
	}
	LL t= exgcd(b,a%b,x,y);
	LL tmp = x;
	x = y;
	y = tmp-a/b*y;
	return t;
}
LL inv(LL v, LL p)
{
	LL x,y;
	LL t = exgcd(v,p,x,y);
	if (t != 1) return 0;
	return (x+p)%p;
}
int gcd(int a,int b)
{
	if (b == 0) return a;
	return gcd(b,a%b);
}
vector<pair<LL,LL> > V;
bool Merge(LL a,LL n1,LL b,LL n2)
{
	LL d = gcd(n1,n2);
	LL c = b-a;
	if (c%d)
		return false;
	c = (c%n2+n2)%n2;
	c /= d;
	n1 /= d;
	n2 /= d;
	c *= inv(n1,n2);
	c %= n2;
	c *= n1*d;
	c += a;
	LL n3 = n1*n2*d;
	V.push_back(MP((c%n3+n3)%n3,n1*n2*d));
	return true;
}
LL solve()
{
	V.clear();
	for (int i=0;i<n;++i)
		b[i]=i+1;
	int t=-1;
	for (int i=0;i+1<n;++i){
		int cnt = 0;
		while (1) {
			++t;
			t=(t+n)%n;
			if (b[t]==0)continue;
			++cnt;
			if (t+1==a[i])break;
		}
		b[a[i]-1] = 0;
		V.push_back(MP(cnt%(n-i),n-i));
	}

	for (int i=0;i<V.size();++i){
		for (int j=0;j<i;++j){
			if (V[i].first >=0 && V[j].first >=0){
				if (gcd(V[i].second,V[j].second) != 1){
					if (Merge(V[i].first,V[i].second,V[j].first,V[j].second)){
						V[i].first = V[j].first = -1;
						break;
					}
					else
						return 0;
				}
			}
		}
	}

	LL M=1;
	LL ans = 0;
	for (int i=0;i<V.size();++i){
		if (V[i].first != -1)
			M*=V[i].second;
	}

	for (int i=0;i<V.size();++i){
		if (V[i].first == -1 ) continue;
		LL tmp = inv(M/V[i].second,V[i].second);
		if (!tmp) return 0;
		ans += V[i].first*tmp*(M/V[i].second);
	}

	ans = (ans%M+M)%M;
	if (ans == 0)
		ans += M;
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (int i=0;i<n;++i){
			int t;
			scanf("%d",&t);
			a[t-1] = i+1;
		}
		LL ans = solve();
		if (ans==0)
			printf("Creation August is a SB!\n");
		else
			printf("%lld\n",ans);
	}
	return 0;
}

```

























