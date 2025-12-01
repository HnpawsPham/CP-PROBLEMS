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

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    ll dp[n][n] = {0};
    for(int i = 0; i < n; i++) dp[i][i] = a[i];

    // for(int i = n - 1; i >= 0; i--)
    //     for(int j = i + 1; j < n; j++)
    //         dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);

    for(int len = 2; len <= n; len++)
        for(int i = 0; i + len - 1 < n; i++){
            int j = i + len - 1;
            dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
        }
    cout<<dp[0][n - 1];
    return 0;
}