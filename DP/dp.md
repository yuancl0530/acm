# 动态规划

## 动态规划的基本思想
将一个问题分解为子问题递归求解，且将中间结果保存以避免重复计算。通常用来求最优解，且最优解的局部也是最优的。求解过程产生多个决策序列，下一步总是依赖上一步的结果，自底向上的求解。
动态规划算法可分解成从先到后的4个步骤：

1. 描述一个最优解的结构，寻找子问题，对问题进行划分。
2. 定义状态。往往将和子问题相关的各个变量的一组取值定义为一个状态。某个状态的值就是这个子问题的解（若有k个变量，一般用K维的数组存储各个状态下的解，并可根据这个数组记录打印求解过程。）。
3. 找出状态转移方程。一般是从一个状态到另一个状态时变量值改变。
4. 以“自底向上”的方式计算最优解的值。 
5. 从已计算的信息中构建出最优解的路径。(最优解是问题达到最优值的一组解)

其中步骤1~4是动态规划求解问题的基础，如果题目只要求最优解的值，则步骤5可以省略。
***
## 最长单增子序列

(LIS Longest Increasing Subsequence)给定一个数列，从中删掉任意若干项剩余的序列叫做它的一个子序列，求它的最长的子序列，满足子序列中的元素是单调递增的。

### 思路一(时间复杂度O(n*n))
**1.子问题:**`lis[i]`表示一第i位结尾的最长单增子序列的长度

**2.状态转移：**lis[i] = max{lis[i],max{lis[j]+1(a[i]>a[j])}}


**3.自底向上求解：**
```
        for (int i = 1;i <= n;i++){
			int j = i-1;
			while (j > 0){
				if (a[i] > a[j]){
					lis[i] = max(lis[i],lis[j]+1);
				}
				j--;
			}
		}
```
### 思路二(时间复杂度O(nlogn))

pos[x]表示所有长度为x的单增的子序列中最后一位的最小值。

每一次二分二分查找满足`x<a[i]`的x的最大值。
pos[x+1] = min(pos[x+1],a[i]);

### 例题
[51nod 1134](https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1134)
#### 题目

给出长度为N的数组，找出这个数组的最长递增子序列。(递增子序列是指，子序列的元素是递增的）
例如：5 1 6 8 2 4 5 10，最长递增子序列是1 2 4 5 10。

#### 思路一代码(TLE)

```
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
#include <list>
#include <set>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
const int maxn = 1e6 + 100;
int a[maxn];
int lis[maxn];
int main()
{
	int n;

	while (cin >> n){
		CL(a);
		CL(lis);
		int ans = 0;
		for (int i = 1;i <= n;i++){
			cin >> a[i];
			lis[i] = 1;
		}
		for (int i = 1;i <= n;i++){
			int j = i-1;
			while (j > 0){
				if (a[i] > a[j]){
					lis[i] = max(lis[i],lis[j]+1);
				}
				j--;
			}
			ans = max(ans,lis[i]);
		}
		cout << ans <<endl;
	}
	return 0;
}

```
#### 思路二代码(AC)

```
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <cctype>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
const int INF = 0x7fffffff;
const int maxn = 5e4+100;
int a[maxn];
int pos[maxn];
int main()
{
    int n;
    int ans = 0;
    while (cin >> n){
        CL(pos);
        for (int i = 1;i <= n;i++){
            cin >> a[i];
        }
        pos[0] = -INF;
        for (int i = 1;i <= n;i++)
            pos[i] = INF;
        for (int i = 1 ;i <= n;i++){
            int l = 0;
            int r = n + 1;
            int mid;
            while (l + 1 < r){
                mid = (l + r) >> 1 ;
                if (pos[mid] <= a[i])
                    l = mid;
                else
                    r = mid;
            }
			l = pos[r] < a[i] ? r : l;
            ans = max(ans,l+1);
            pos[l+1] = min(pos[l+1],a[i]);
        }
        cout << ans <<endl;
    }
    return 0;
}
```
*** 

## 求子序列的个数
**子序列的定义：**对于一个序列a=a[1],a[2],......a[n]。则非空序列a'=a[p1],a[p2]......a[pm]为a的一个子序列，其中1<=p1<p2<.....<pm<=n。
例如4,14,2,3和14,1,2,3都为4,13,14,1,2,3的子序列。


对于一个集合(不包含重复元素的序列)来说，一个集合的子集(子序列)的个数为2^n。  
求解的方法:  
>设原序列的子序列个数为m,则序列中增加一个元素时，  
所有不包含x这个元素的子集个数为m个  
所有包含x这个元素的子集个数也为m个(相当于向原来每个子集中添加x这个元素)
所以，增加元素x后子集的总数为`2*m`  
1个元素的的子集个数为2个(包含空序列)  
则两个元素的子集列个数为2^2个  
……  
包含n个元素的集合的子集(含空集)的总数为2^n

接下来我们讨论包含重复元素的序列的子序列的个数。  
>我们每向序列中添加一个元素x时  
如果这个元素与前面的元素不重复，那么此时子序列的个数为原来的2倍(同集合);  
如果这个元素与前面的元素有重复，如果也按照子序列的个数为原来的2倍的方法来计算的话，就会与前面所有以x为结尾的子序列重复，因此我们要减去这一部分(也就是加入上一个x前的子序列的个数)

**1.子问题:**dp[i]表示序列前i位的子序列的个数

**2.状态转移：**  
>加入第i个元素时，  
如果第i个元素与前面的元素不重复dp[i] =2 * dp[i-1]  
如果第i个元素与前面第j个元素重复，那么dp[i] = 2*dp[i-1] - dp[j-1]  
**3.自底向上求解：**  
pos[x]表示元素x出现的位置
```
    dp[0] = 1;
    for (int i = 1;i <= n;i++){
        dp[i] = dp[i-1] * 2;
        if (pos[a[i]] > 0){
            dp[i] -= dp[pos[a[i]]-1];
        }
        pos[a[i]] = i;
    }
```
### 例题
[51nod 1202](https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1202)
#### 题目
子序列的定义：对于一个序列a=a[1],a[2],......a[n]。则非空序列a'=a[p1],a[p2]......a[pm]为a的一个子序列，其中1<=p1<p2<.....<pm<=n。
例如4,14,2,3和14,1,2,3都为4,13,14,1,2,3的子序列。对于给出序列a，有些子序列可能是相同的，这里只算做1个，请输出a的不同子序列的数量。由于答案比较大，输出Mod 10^9 + 7的结果即可。
#### 代码
```
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
#include <list>
#include <set>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
const int maxn = 1e6 + 100;
const int MOD = 1e9 + 7;
LL dp[maxn];
int pos[maxn];
int a[maxn];
int main()
{
	int n;
	ios::sync_with_stdio(false);
	while (cin >> n){
		CL(pos);
		CL(dp);
		for (int i = 1;i <= n;i++){
			cin >> a[i];
		}
		dp[0] = 1;
		for (int i = 1;i <= n;i++){
			dp[i] =( 2 * dp[i-1] )%MOD;
			if (pos[a[i]]){
				dp[i] = (dp[i] - dp[pos[a[i]]-1] + MOD) % MOD;//这里要+MOD，避免出现负数
			}
			pos[a[i]] = i;
		}
		cout << dp[n] - 1 <<endl;
	}
	return 0;
}

```





***
## 最长公共子序列问题(LCS)


**1.子问题:**`lcs[x][y]`表示a串的前x位，和b串的前y位的最长公共子序列长度。

**2.状态转移：**

>(1)当`a[x] == b[y]`时,`lcs[x][y] = lcs[x-1][y-1] + 1`  
(2)当`a[x] != b[y]`时，`lcs[x][y] = max{lcs[x-1][y],lcs[x][y-1]}`  
相当于递归求解到a[x']==b[y'] (0<=x'<=x,0<=y'<=y)的最大值。

**3.自底向上求解：**

```
    for(int x= 1;x <= lena;x++){
        for (int y = 1y <= lenb;y++){
            if (a[x] == b[y]){
                lcs[x][y] = lcs[x-1][y-1] + 1;
            }
            else{
                lcs = max(lcs[x-1][y],lcs[x][y-1]);
            }
        }
    }
```

### 例题

[51nod 1006](https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1006)

#### 题目(LCS+记录路径)
>给出两个字符串A B，求A与B的最长公共子序列（子序列不要求是连续的）。  
比如两个串为：  
abcicba  
abdkscab  
ab是两个串的子序列，abc也是，abca也是，其中abca是这两个字符串最长的子序列。

#### 代码

```
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
const int maxn = 1e3 + 10;
struct Node{
    int len;
    char c;//当前子序列的最后一个字符
    int from;
}lcs[maxn][maxn];
char a[maxn];
char b[maxn];
void solve(int x,int y)
{
    if (x < 0 || y < 0 ||lcs[x][y].len == 0)return ;
    if (lcs[x][y].from == 0)
        solve(x-1,y-1);
    else if (lcs[x][y].from == 1)
        solve(x-1,y);
    else if (lcs[x][y].from == 2)
        solve(x,y-1);
    if (!lcs[x][y].from)
        printf("%c",lcs[x][y].c);
}
int main()
{
    while (scanf("%s",a) != EOF){
        scanf("%s",b);
        int end_i;
        int end_j;
        int ans_l = 0;
        memset(lcs,0,sizeof lcs);

        for (int i = 1;a[i-1];i++){
            for (int j = 1;b[j-1];j++){
                if (a[i-1] == b[j-1]){
                    lcs[i][j].len = lcs[i-1][j-1].len+1;
                    lcs[i][j].c = a[i-1];
                    lcs[i][j].from = 0;
                    if (lcs[i][j].len> ans_l){
                        end_i = i;
                        end_j = j;
                        ans_l = lcs[i-1][j-1].len + 1;
                    }
                }
                else {
                    if (lcs[i-1][j].len > lcs[i][j-1].len){
                        lcs[i][j].len = lcs[i-1][j].len;
                        lcs[i][j].c = lcs[i-1][j].c;
                        lcs[i][j].from = 1;
                    }
                    else {
                        lcs[i][j].len = lcs[i][j-1].len;
                        lcs[i][j].c = lcs[i][j-1].c;
                        lcs[i][j].from = 2;
                    }
                }
            }
        }
        solve(end_i,end_j);
        cout<<endl;
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
    }

    return 0;
}

```

***
## 编辑距离问题

编辑距离，又称Levenshtein距离（也叫做Edit Distance），是指两个字串之间，由一个转成另一个所需的最少编辑操作次数。许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。  
例如将kitten一字转成sitting：  
sitten （k->s）  
sittin （e->i）  
sitting （->g）  
所以kitten和sitting的编辑距离是3。  
给出两个字符串a,b，求a和b的编辑距离。

我们可以看成字符串对齐的问题，事实上从生物信息学对比基因的角度，我们可以这样理解问题。

给定字符串S和T，我们可以用一种特殊字符促成两个字符串的对齐。我们加的特殊字符是“-”, 我们允许在S和T中任意添加这种特殊字符使得它长度相同，然后让这两个串“对齐”，最终两个串相同位置出现了不同字符，就扣1分，我们要使得这两个串对齐扣分尽量少。

对于例子 我们实际上采取了这样的对齐方式：

12345  
ABCF-  
DB-FG  


**1.子问题:**`用dp[x][y]`表示表示编辑a串前x位和b串前y位的编辑距离

**2.状态转移：**

>(1)当第x位和第y位对齐时  
(1.1)若`a[x]==b[y]`时,此时不需要编辑，`dp[x][y] = dp[x-1][y-1]`  
(2)当`a[x] != b[y]`时,此时需要编辑，`dp[x][y] = dp[x-1][y-1] + 1`  
(2)当第x位和第y位不对齐时  
(2.1)当第x位和第y-1位对齐时，此时需要编辑,`dp[x][y] = dp[x][y-1] + 1`
(2.2)当第x-1位和第y位对其时。此时需要编辑,`dp[x][y] = dp[x-1][y] + 1`

**3.自底向上求解：**

初始化dp
```
    for (int i = 1;i <= lena;i++){
        dp[i][0] = i;
    }
    for (int i = 0;i <= lenb;i++){
        dp[0][i] = i;
    }
```
求解
```
    for (int i = 1;i <= lena;i++){
        for (int j = 1;j <= lenb;j++){
            dp[i][j] = min(dp[x][y] + (a[i-1] != b[j-1]),min(dp[x-1][y],dp[x][y-1]) + 1 );
        }
    }
```

### 例题
[51nod 1183](https://www.51nod.com/onlineJudge/submitDetail.html#!judgeId=296616)

#### 题目
编辑距离，又称Levenshtein距离（也叫做Edit Distance），是指两个字串之间，由一个转成另一个所需的最少编辑操作次数。许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。  
例如将kitten一字转成sitting：  
sitten (k->s)  
sittin (e->i)  
sitting (->g)  
所以kitten和sitting的编辑距离是3。俄罗斯科学家Vladimir Levenshtein在1965年提出这个概念。
给出两个字符串a,b，求a和b的编辑距离。
#### 代码

```
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <cctype>
using namespace std;
#define CL(a) memset(a,0,sizeof(a));
#define LL long long
const int INF= 0x7fffffff;
const int maxn = 1e3 + 100;
long long dp[maxn][maxn];
char a[maxn];
char b[maxn];

int main()
{
    while (cin >> a && cin >> b){
        int lena = strlen(a);
        int lenb = strlen(b);
        CL(dp);
        for (int i = 1;i <= lena;i++)
            dp[i][0] = i;
        for (int i = 1;i <= lenb;i++)
            dp[0][i] = i;
        for (int i = 1;i <= lena;i++){
            for (int j = 1;j <= lenb;j++){

                dp[i][j] = min(dp[i-1][j-1] + (a[i-1] != b[j-1]),min(dp[i-1][j]+1,dp[i][j-1]+1));

            }
        }
        cout << dp[lena][lenb] << endl;
    }
    return 0;
}

```

***
## 背包问题

### 01背包: 
有N件物品和一个重量为M的背包。（每种物品均只有一件）第i件物品的重量是w[i]，价值是p[i]。求解将哪些物品装入背包可使价值总和最大。

1. **用子问题定义状态**：用`dp[i][j]`表示前i件物品放在一个容量为j的背包中可以取得的最大值。

2. **状态转移：** `dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]] + p[i])`

3. **自底向上计算最优解：**
```
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= m;j++){
            if (j >= w[i]){
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]] + p[i]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
```

***优化后代码***

```
    
    for (int i = 1;i <= n;i++){
        for (int j = m;j >= w[i];j--){
            f[j] = max(f[j],f[j-w[i]] + p[i]);
        }
    }
```
#### 例题


[51nod 1085](https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1085)

##### 题目

在N件物品取出若干件放在容量为W的背包里，每件物品的体积为W1，W2……Wn（Wi为整数），与之相对应的价值为P1,P2……Pn（Pi为整数）。求背包能够容纳的最大价值。

##### 代码

```
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
#include <list>
#include <set>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
#define YOUHUA 0
const int maxn = 1e4 + 10;
int w[maxn];
int p[maxn];
int dp[110][maxn];
int f[maxn];
int main()
{
	int n,m;
	ios::sync_with_stdio(false);
    while (cin >> n){
        cin >> m;
        for (int i =1;i <= n;i++)
            cin >> w[i] >> p[i];
#if YOUHUA==0 //优化后
        for (int i = 1;i <= n;i++){
        	for (int j = 1;j <= m;j++){
        	    if (j >= w[i]){
         	       dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]] + p[i]);
         	   }
       	    	else {
                	dp[i][j] = dp[i-1][j];
            	}
       		}
   		}
		cout << dp[n][m] <<endl;
#else        //优化前
	    for (int i = 1;i <= n;i++){
            for (int j = m;j >= w[i];j--){
                f[j] = max(f[j],f[j-w[i]] + p[i]);
            }
        }
        cout << f[m] <<endl;
#endif
	}
	return 0;
}

```

### 多重背包:
有N种物品和一个重量为M的背包。第i种物品最多有c[i]件可用，每件重量是w[i]，价值是p[i]。求解将哪些物品装入背包可使这些物品的费用总和不超过背包重量W，且价值总和最大。

#### 方法一（时间复杂度O(n\*w\*max(ci))）：

1. **用子问题定义状态**：用`dp[i][j]`表示前i件物品放在一个容量为j的背包中可以取得的最大值。

2. **状态转移：** `dp[i][j] = max(dp[i-1][j],dp[i-1][j-k*w[i]] + k*p[i])  (0 <= k <= min(j/w[i],c[i]))`

3. **自底向上计算最优解：**
```
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= m;j++){
            for (int k = 0;k <= c[i] && k*w[i] <=j;k++){
                dp[i][j] = max(dp[i][j],dp[i-1][j-k*w[i]] + k*p[i])
            }
        }
    }
```

***优化后代码***

```
    
    for (int i = 1;i <= n;i++){
        for (int j = m;j >= w[i];j--){
            for (int k = 1;k <= c[i] && k*w[i] <=j;k++){
                f[j] = max(f[j-k*w[i]]+k*p[i],f[j]);
            }
        }
    }
```
#### 思路2(时间复杂度O(w\*sum(log(ci))))：


我们看看有没有办法变成更好的0-1背包问题。我们把第i种物品看成单个的，一个一个的，我们想想二进制，任何一个数都可以由二的幂表示。

我们试试看，比如Ci  = 14，我们可以把它化成如下4个物品：

重量是Wi，体积是Vi
重量是2 * Wi , 体积是2 * Vi
重量是4 * Wi , 体积是4 * Vi
重量是7 * Wi , 体积是7 * Vi

*注意最后我们不能取，重量是8 * Wi , 体积是8 * Vi 因为那样总的个数是1 ＋ 2 ＋ 4 ＋ 8 ＝ 15个了，我们不能多取对吧？*

我们用这4个物品代替原来的14个物品，大家可以试试原来物品无论取多少个，重量和体积都可以靠我们这几个物品凑出来，这说明我们这种分配方式和原来是等价的。

我们转化为一般方法，对于Ci ,我们的拆分方法是：

1，2，4，8…… 同时Ci减去这些值，如果Ci不够减了，则把最后剩余的算上，同时我们体积也对应乘以这些系数。这样Ci个同一种物品，被我们变成了logCi个物品了。
于是这个问题就转化成了0-1背包问题

#### 例题
[51nod 1086](https://www.51nod.com/onlineJudge/questionCode.html#!problemId=1086)
##### 题目

在N件物品取出若干件放在容量为W的背包里，每件物品的体积为W1，W2……Wn（Wi为整数），与之相对应的价值为P1,P2……Pn（Pi为整数）。求背包能够容纳的最大价值。

##### 代码

***思路一代码(TLE)***
```
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
#include <list>
#include <set>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
#define YOUHUA 1
const int maxn = 5e4 + 100;
int w[maxn];
int c[maxn];
int p[maxn];
int dp[110][maxn];
int f[maxn];
int main()
{
	int n,m;
	while (cin >> n >>m){
		for (int i = 1;i <= n;i++){
			cin >> w[i] >> p[i] >>c[i];
		}
#if YOUHUA==0 //优化前
		for (int i = 1;i <= n;i++){
        	for (int j = 1;j <= m;j++){
            	for (int k = 0;k <= c[i] && k*w[i] <=j;k++){
                	dp[i][j] = max(dp[i][j],dp[i-1][j-k*w[i]] + k*p[i]);
        		}
        	}
		}
		cout << dp[n][m] << endl;
#else          //优化后
	   for (int i = 1;i <= n;i++){
        	for (int j = m;j >= w[i];j--){
            	for (int k = 1;k <= c[i] && k*w[i] <=j;k++){
                	f[j] = max(f[j-k*w[i]]+k*p[i],f[j]);
                }
            }
    	}
		cout << f[m] << endl;
#endif
	}
	return 0;
}


```
*** 思路二代码(AC)***

```
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <list>
#include <set>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(b))
#define INF 0x7fffffff
#define LL long long
const int maxn = 5e4 + 100;
struct Node
{
	int w;
	int p;
}a[maxn];
int dp[maxn];
int main()
{
	int n,m;
	ios::sync_with_stdio(false);
	while (cin >> n >> m){
		int w,p,c;
		int cnt = 0;
		for (int i = 1;i <= n;i++){
			cin >> w >> p >> c;
			int t = 1;
			while (c - t > 0){
				a[++cnt].w = w * t;
				a[cnt].p = p * t;
				c -= t;
				t *= 2;
			}
			a[++cnt].w = w * c;
			a[cnt].p = p * c;
		}
		CL(dp);
		for (int i = 1;i <= cnt;i++){
			for (int j = m;j >= a[i].w;j--){
				dp[j] = max(dp[j],dp[j-a[i].w] + a[i].p);
			}
		}
		cout << dp[m] << endl;
	}
	return 0;
}

```

### 完全背包:
有n种物品和一个重量为m的背包，每种物品都有无限件可用。第i种物品的重量是w[i]，价值是p[i]。求解将哪些物品装入背包可使这些物品的费用总和不超过背包重量，且价值总和最大。
和多重背包的解法一样，只不过没有物品数量的限制

1. **用子问题定义状态**：用`f[i]`表示物品放在一个容量为i的背包中可以取得的最大值。

2. **状态转移：** `f[i] = max(f[i],f[i-k*w[j]] + k*p[j]) (k*w[j] <= i)`

3. **自底向上计算最优解：**

```
    for (int i = 1;i <= n;i++){
        for (int j = m;j >= w[i];j--){
            for (int k = 1;k * w[i] <=j;k++){
                f[j] = max(f[j],f[j-k*w[i]] + k*w[i]);
            }
        }
    }
```

#### 例题
[HDU 1248](http://acm.hdu.edu.cn/showproblem.php?pid=1248)

##### 代码  
```
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
#include <list>
#include <set>
using namespace std;
#define CL(a) memset(a,0,sizeof(a))
#define Cl(a,b) memset(a,b,sizeof(a))
#define INF 0x7fffffff
#define LL long long
const int maxn = 1e6 + 100;
const int MAX = 1e4;
int f[maxn];
int w[10];
int main()
{
	w[1] = 150;
	w[2] = 200;
	w[3] = 350;
	int t;
	int m;
	for (int i = 1;i <= 3;i++){
        for (int j = MAX;j >= w[i];j--){
            for (int k = 1;k * w[i] <=j;k++){
                f[j] = max(f[j],f[j-k*w[i]] + k*w[i]);
            }
		}
    }
	scanf("%d",&t);
	while (t--){
		scanf("%d",&m);
		printf("%d\n",m-f[m]);
	}
	return 0;
}


```



***
