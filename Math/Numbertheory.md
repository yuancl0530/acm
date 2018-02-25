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
int exgcd(int a,int b,int &x,int &c)
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
由$于gcd(a,b)|a$,  
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
























































































