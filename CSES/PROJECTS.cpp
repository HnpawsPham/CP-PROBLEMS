#include <bits/stdc++.h>
using namespace std;
#define el "\n"
using ll = long long;

struct pro{
    ll l, r, w;
};

int n;
const int maxn = 2 * (int)1e5 + 5;
struct pro a[maxn];

bool compare(pro a, pro b){
    return a.r < b.r;
}

int find(int i){
    int l = 0, r = i - 1;
    int res = -1;

    while(l <= r){
        int mid = (l + r) /2;
        
        if(a[mid].r < a[i].l){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i =0;i<n;i++) cin>>a[i].l>>a[i].r>>a[i].w;
    sort(a, a + n, compare);

    ll dp[n];
    dp[0] = a[0].w;
    
    for(int i = 1; i < n; i++){
        ll w = a[i].w;
        int t = find(i);

        if(t != -1) w += dp[t];

        dp[i] = max(dp[i - 1], w);
    }
    cout<<dp[n - 1]<<el;

    return 0;
}