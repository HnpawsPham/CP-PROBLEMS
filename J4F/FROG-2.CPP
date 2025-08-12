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
const int oo = 1e9 + 6;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    vi dp(n, oo);
    dp[0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = max(i - k, 0); j < i; j++)
            dp[i] = min(dp[i], dp[j] + abs(a[i] - a[j]));
    }
    cout<<dp[n - 1];
    return 0;
}