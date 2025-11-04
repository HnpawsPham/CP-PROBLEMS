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

int n;
const ll oo = 1e14;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    ll p[n + 1] = {0};
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i - 1];

    vector<vll> dp(n, vll(n, oo));
    for(int i = 0; i < n; i++) dp[i][i] = 0;

    for(int len = 2; len <= n; len++)
        for(int i = 0; i <= n - len; i++){
            int j = i + len - 1;
            for(int k = i; k < j; k++)
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + p[j + 1] - p[i]);
        }
    cout<<dp[0][n - 1];
    return 0;
}