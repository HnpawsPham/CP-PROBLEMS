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

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<vi> dp(n, vi(n, 0));
    for(int len = 2; len <= n; len++)
        for(int i = 0; i + len < n; i++){  
            int j = i + len;
            dp[i][j] = INT_MAX;

            for(int k = i + 1; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[j] * a[k]);
        }
        
    cout<<dp[0][n - 1];
    return 0;
}