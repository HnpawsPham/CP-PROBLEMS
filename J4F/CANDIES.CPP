#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, k;
const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<ll> dp(k + 1, 0);
    dp[0] = 1;

    for(int i = 0; i < n; i++){
        vi p(k + 1);
        p[0] = dp[0];
        for(int j = 1; j <= k; j++)
            p[j] = (p[j - 1] + dp[j]) % MOD; 

        vector<ll> tmp(k + 1, 0);
        for(int j = 0; j <= k; j++){
            int l = j - a[i];
            if(l > 0) tmp[j] = (p[j] - p[l - 1] + MOD) % MOD;
            else tmp[j] = p[j];
        }

        dp = tmp;
    }
    cout<<dp[k];
    return 0;
}