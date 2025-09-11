#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const ll oo = 1e18 + 5;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n], w[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>w[i];

    vector<ll> dp(n, oo);
    dp[0] = 0;
    for(int i = 1; i < n; i++)  
        for(int j = 0; j < i; j++)
            dp[i] = min(dp[i], dp[j] + a[i] * w[j]);
            
    cout<<dp[n - 1];
    return 0;
}