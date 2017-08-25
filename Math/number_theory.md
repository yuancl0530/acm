## 欧几里德算法  

$gcd(a,b) = gcd(b,a\%b)$  

### 证明  
要证明$gcd(a,b) = gcd(b,a\%b)$,  
只需要证明,$gcd(a,b)|gcd(b,a\%b),并且gcd(b,b\%a)|gcd(a,b)$  
1.$gcd(a,b)|gcd(b,a\%b)$  
设$d=gcd(a,b),则d|a并且d|b,a\%b=a-a/b*b,由于d|a并且d|b,所以d|(a-a/b*b),即d|(a\%b),所以gcd(a,b)|gcd(b,a\%b)$     

2.$gcd(b,a\%b)|gcd(a,b)$  
设$d=gcd(b,a\%b)则d|b,d|(a\%b),即d|(a-a/b*b),所以d|a,则d|gcd(a,b),所以gcd(b,a\%b)|gcd(a,b)$  
得证
### 实现代码
```
int gcd(int a,int b)
{
    if (b==0)return a;
    return gcd(b,b%a);
}
```

## 扩展欧几里德算法  
### 基本算法： 
对于不完全为 0 的非负整数 a，b，gcd（a，b）表示 a，b 的最大公约数，必然存在整数对 x，y ，使得 gcd（a，b）=ax+by  
$设d=gcd(a,b)$,
$$ax+by=d.........(1)$$  
存在x',y',  
$$bx'+(a\%b)y'=d....(2)$$
展开(2)得,$bx'+(a-a/b*b)y',=>ay'+b(x'-a/b*y')$,  
则\begin{cases}x=y'\\y=x'-a/b*y\end{cases}
### 实现代码
```
int exgcd(int a,int b,int &x,int &y)
{
    if(b==0){x=1,y=0;return a;}
    int d = exgcd(b,a%b,x,y);
    int t = y;
    x = y;
    y = t - a/b*y;
    return d;
}
```
### 相关应用
#### (1)求解不定方程 
对于不定方程$ax+by=c,若gcd(a,b)|c,则该线性方程有解,否则无解.$  

>证明:$$设ax_0+by_0=gcd(a,b)...(1)$$ $$ax+by=c...........(2)$$ $$(1)+(2)得:a(x_0+x)+b(y_0+y)=gcd(a,b)+c$$  
由$于gcd(a-)|a$,  
$gcd(a,b) |b$,  
则$gcd(a,b)|(a(x_0+x)+b(y_0+y))$,  
即$gcd(a,b)|(gcd(a,b)+c)$,所以$gcd(a,b)|c$  

找整数解的方法:  
>$设ax_0+by_0=gcd(a,b)$,  
则$ax_0*(c/gcd(a,b))+by_o*(c/gcd(a,b))=c,$  
所以\begin{cases}x=x_0*(c/gcd(a,b))\\y=y_0*(c/gcd(a,b)\end{cases}就是原线性方程的一组特解  
通解：　

\begin{cases}
x = x+(b/gcd(a,b))*t\\
y = y - (a/gcd(a,b))*t
\end{cases}

#### (2)求解线性同余方程　
同余方程 $ax\equiv b(mod n)$对于未知数 x 有解，当且仅当 $gcd(a,n)|b$。且方程有解时，方程有 $gcd(a,n)$ 个解。 


求解方程 $ax≡b (mod n)$ 相当于求解方程 $ax+ ny= b$, (x, y为整数)
>证明：设$r=ax\%n=b\%n$,   
$ax=pn+r$,  
$b=qn+r$,  
则ax=pn+(b-qn),   
化简得$ax+(q-p)n=b$,  
令$ｙ=p-q$,则$ax+ny=b$,也就转化成了求解不定方程． 
#### (3)求解模逆元　
$ax\equiv 1(mod n)$,如果$gcd(a,n)=1$,则方程在［0,n)只有唯一解．　
>证明：根据以上推倒，设$x_0$是[0,n)内的一个解，$x=x_0+n/gcd(a,n)$,由于gcd(a,n)=1,所以$x_0$是唯一解　



## 欧拉函数相关　
### 欧拉函数　
对于一个正整数n,小于`n`且和`n`互质的正整数(包括 1)的个数，记作$\phi(n)$ 。  
#### 欧拉函数的性质　
1.$n=p^k$型欧拉函数  
(1)$k=1$时，$\phi(n)=\phi(p)=p-1$  
(2)$k\neq1$时，$\phi(n)=p^k-1-(p^{k-1}-1)=p^{k-1}(p-1)$  
>证明：与$n$互质元素的集合$Zn=\{1,2,3,4,5,...,n-1\}-\{p,2p,3p,4p,...,p(p^{k-1}-1)\}$  

2.mn型欧拉函数  
对于两个不同p,q,$gcd(p,q)=1$,n=p*q,$\phi(n)=(p-1)*(q-1)$  
>证明：与$n$互质元素的集合$Zn=\{1,2,3,...,n-1\}-\{p,2p,...,(q-1)*p\}-\{q,2q,...,(p-1)*q\}$  
$\phi(n)=(p*q-1)-(q-1)-(p-1)=p*q-p-q+1=(p-1)*(q-1)=\phi(p)*\phi(q)$  

3.任意正整数的欧拉函数  
任意一个整数n都可以表示为其质因子的乘积:
$n=p_1^{k_1}p_2^{k_2}p_3^{k_3}...p_i^{k_i}...p_l^{k_l}$($k_i\neq0,l为n质因子的个数$)  

$\phi(n)=n(1-\frac{1}{p_1})(1-\frac{1}{p_2})(1-\frac{1}{p_3})....(1-\frac{1}{p_l})$  

### 求欧拉函数　　
1.求小于或等于n,且与n互质的个数:
```
int phi(int n)
{
    int ret=n;
    for (int i=2;i<sqrt(n);i++){
        if (n%q==0){
            ret=ret/i*(i-1);
            while (n%i==0){
                n/=i;
            }
        }
    }
    if (n>1)
        ret=ret/n*(n-1);
    return n;
}
```
2.筛法求欧拉函数　　
```
int prime[N];
int phi[N];
void oula(int n)
{
    bool isprime[N];
    memset(isprime,1,sizeof(isprime));
    for (int i = 2;i <= n;i++){
        if (isprime[i])
            {prime[++prime[0]] = i,phi[i]=i-1;}
        for (int j = 1;j <= prime[0];j++){
            int k = i*prime[j];
            if (k>n)break;
            isprime[k]=0;
            if (i%prime[j]==0){
                phi[k] = phi[i]*prime[j];
            }
            else{
                phi[k] = phi[i]*(prime[j]-1);
            }
        }
    }

}
```
### 欧拉定理　　
若$gcd(a,n)=1$,$$a^{\phi(n)}\equiv1 \pmod n$$
>证明：  
1.令$Zn=\{x_1,x_2,x_3,...,x_{\phi(n)}\}$,  
$S=\{a*x_1 mod n,a*x_2 mod n,...,a*x_{phi(n)}\}$  
$Zn=Sn$  
(1)$gcd(a,n)=1,gcd(x_i,n)=1,gcd(a*x_i,n)=1,(a*x_i\%n\in Zn)$  
(2)$i\neq j,a*x_i \%n \neq a*x_j \%n$  
2.$a^{\phi(n)}*x_1*x_2*x_3*...*x_{\phi(n)}\mod n$   
$=(a*x_1)(a*x_2)(a*x_3)..(a*x_{\phi(n)})\mod n$  
$=(a*x_1 \mod n)(a*x_2\mod n)..(a*x_{\phi(n)} \mod n)\mod n$  
$=x_1*x_2*x_3*...*x_{\phi(n)}\mod n$    
$gcd(x_i,n)=1$  
$a^{\phi(n)}\equiv 1\pmod n$
### 费马小定理　　
若p是素数，并且$gcd(a,p)=1$,则$$a^{p-1}\equiv1\pmod p$$  

## 莫比乌斯函数  
### 表达式  
1）莫比乌斯函数μ(n)的定义域是N  
2）μ(1)=1  
3）当n存在平方因子时，μ(n)=0  
4）当n是素数或奇数个不同素数之积时，μ(n)=-1  
5）当n是偶数个不同素数之积时，μ(n)=1  
$$\mu(n)=\begin{cases}
1\quad n=1\\
(-1)^k\quad n=p_1p_2p_3..p_k\\
0\quad other
\end{cases}
$$
















































































