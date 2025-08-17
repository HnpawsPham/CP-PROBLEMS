#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, maxpts;
    cin>>n>>k>>maxpts;

    if(k == 0 || k - 1 + maxpts <= n) return cout<<1.0, 0;

    vector<db> dp(n + 1, 0);
    dp[0] = 1.0;

    db sum = 1, res = 0;
    for(int i = 1; i <= n; i++){
        dp[i] = sum / maxpts;

        if(i < k) sum += dp[i];
        else res += dp[i];

        if(i - maxpts >= 0) sum -= dp[i - maxpts];
    }
    cout<<res;
    return 0;
}