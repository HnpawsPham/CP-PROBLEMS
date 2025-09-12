#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const ll oo = 1e16;

ll calc(int x){
    return 1LL * x* x;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    ll p[n + 1] = {0};
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i];
 
    ll dp[n + 1][n + 1];
    vector<vi> opt(n + 1, vi(n + 1, 0));
    for(int i = 1; i <= n; i++) {
        dp[i][i] = 0;
        opt[i][i] = i;
    }

    ll res = 0;
    for(int len = 2; len <= n; len++)
        for(int l = 1; l <= n - len  + 1; l++){
            int r = l + len - 1;
            dp[l][r] = oo;

            int st = opt[l][r - 1], en = opt[l + 1][r];
            if(st > en) swap(st, en);

            for(int k = st; k <= en; k++){
                ll w = dp[l][k] + dp[k + 1][r] + calc(p[r] - p[l - 1]);

                if(w < dp[l][r]){
                    dp[l][r] = w;
                    opt[l][r] = k;
                }
            }
    }
    cout<<dp[1][n];
    return 0;
}