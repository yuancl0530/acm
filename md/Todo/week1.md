# 寒假第一周

## Jan29  
* 打Codeforces Round #459 (Div. 2)  
> solved 2 of 5

## Jan30
* 补CF Round #459 C题
> ### 解题思路  
动态规划  
dp[l][r]表示区间[l,r]是否匹配  
**状态转移:**  
1.if s[l]和s[r]匹配 && dp[l+1][r-1]==1  
    dp[l][r] = 1  
2.if dp[l][j]==1  && dp[j+1][r]==1  (j$\in$(l,r) )  
    dp[l][r] = 1  
**优化:**  
ml[i]表示 最大j,使dp[i][j]==1  
mr[i]表示 最小j,使dp[j][i]==1  
对于上面第二种情况，$j \in [ mr[r]-1,ml[j]+1 ]$  
> ### 代码:  
[https://github.com/yuancl0530/acm/blob/master/contest/CF_Round459_Div2/c.cpp](https://github.com/yuancl0530/acm/blob/master/contest/CF_Round459_Div2/c.cpp)


## Jan31
* 刷白书
* 打Codeforces Round #460 (Div. 2)
> solved 3 of 6

## Feb 1
* 刷白书
* 补CF Round #460 D题
>### 解题思路  
>有环的话直接输出-1,  
否则输出某个字母出现的最大次数  
**方法:拓扑排序+DP**
>### 代码 
[https://github.com/yuancl0530/acm/blob/master/contest/CF_Round460_Div2/d.cpp](https://github.com/yuancl0530/acm/blob/master/contest/CF_Round460_Div2/d.cpp)  
## Feb 2/3
* 做近期没打的CF题目
