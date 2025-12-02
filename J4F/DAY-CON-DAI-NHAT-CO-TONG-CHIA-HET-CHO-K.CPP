#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    int dp[n + 1][k];
    // for(int i = 1; i <= n; i++) dp[i][a[i] % k] = 1;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j < k; j++) dp[i][j] = - n - 5;
    
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 0; j < k; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j - a[i] % k + k) % k] + 1);

    cout<<dp[n][0];
    return 0;
}

// 10 3
// 2 3 5 7 9 6 12 7 11 15
