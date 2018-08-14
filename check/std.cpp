#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10, M = 1e6, mod = 1e9+7, inf = 2e9;

int T,n,q,a[N],l[N*36],r[N*36],v[N*36],sz,root[N],ans[N],last[N];

void update(int x, int &y, int ll, int rr, int k,int c) {
     y = ++sz;
     v[y] = v[x] + c;
     r[y] = r[x];
     l[y] = l[x];
     if(ll == rr) return ;
     int mid = (ll+rr)>>1;
     if(k <= mid) update(l[x], l[y], ll, mid, k,c);
     else update(r[x], r[y], mid + 1, rr, k,c);
}
int query(int x,int ll,int rr,int s,int t) {
    if (s <= ll && rr <= t) return v[x];
    int mid = ll + rr >> 1, res = 0;
    if (s <= mid) res += query(l[x], ll, mid, s, t);
    if (t > mid) res += query(r[x], mid + 1, rr, s, t);
    return res;
}

int finds(int x,int ll,int rr,int k) {
        if(ll == rr) return ll;
        int mid = ll + rr >> 1;
        if(v[l[x]] >= k) return finds(l[x],ll,mid,k);
        else return finds(r[x],mid+1,rr,k-v[l[x]]);
}

int main() {
        int cas = 0;
        scanf("%d",&T);
        while(T--) {
            scanf("%d%d",&n,&q);
            sz = 0;
            memset(last,0,sizeof(last));
            memset(v,0,sizeof(v));
            memset(l,0,sizeof(l));
            memset(r,0,sizeof(r));
            ans[0] = 0;
            root[n+1] = 0;
            for(int i = 1; i <= n; ++i) scanf("%d",&a[i]);
            for(int i = n; i >= 1; --i) {
                int x = root[i] = 0;
                update(root[i+1],x,1,n,i,1);
                if(last[a[i]]) {
                    update(x,root[i],1,n,last[a[i]],-1);
                } else root[i] = x;
                last[a[i]] = i;
            }
            int L,R;
            for(int i = 1; i <= q; ++i) {
                scanf("%d%d",&L,&R);
                L = ((L + ans[i-1])%n) + 1;
                R = ((R + ans[i-1])%n) + 1;
                if(L > R) swap(L,R);
                int sum = query(root[L],1,n,L,R)  + 1 >> 1;
                ans[i] = finds(root[L],1,n,sum);
            }
            printf("Case #%d: ",++cas);
            for(int i = 1; i < q; ++i)  printf("%d ",ans[i]);
            cout<<ans[q]<<endl;
        }
        return 0;
}
