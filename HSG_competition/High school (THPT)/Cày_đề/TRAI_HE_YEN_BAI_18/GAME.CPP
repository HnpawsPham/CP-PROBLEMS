#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;
const int maxn = 1e6 + 5;
ll a[maxn];

int Max(int a, int b, int c){
    return max({a, b, c});
}

ll sol1(){
    ll sum;
    if(n == 1) return a[1];
    if(n == 2) return a[1] + a[2];
    if(n == 3) return Max(a[1] + a[2], a[2] + a[3], a[1] + a[3]);

    ll c1 = a[1], c2 = a[1] + a[2], c3 = a[1] + a[3];
    for(int i = 4; i < n; i++){
        sum = Max(c1 + a[i] + a[i - 1], c2 + a[i], c3);
        c1 = c2;
        c2 = c3;
        c3 = sum;
    }
    return sum;
}

ll sol2(){
    ll dp[n + 1];
    dp[0] = 0;
    dp[1] = a[1];
    dp[2] = a[1] + a[2];
    dp[3] = Max(a[1] + a[2], a[2] + a[3], a[1] + a[3]);

    for(int i = 4; i <= n; i++){
        dp[i] = Max(dp[i - 1], dp[i - 2] + a[i], dp[i - 3] + a[i - 1] + a[i]);
        dp[i - 3] = dp[i - 2];
        dp[i - 2] = dp[i - 1];
        dp[i - 1] = dp[i];
    }
    return dp[n];
}

int main(){
    freopen("GAME.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i];
    cout<<sol1();
    return 0;
}