#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc;

ll sol(){
    int n;
    cin>>n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    ll dp[n + 1] = {0};
    dp[1] = a[1];
    for(int i = 2; i <= n; i++)
        dp[i] = min(dp[i - 1] + a[i] - 1, dp[i - 2] + a[i - 1] + max(0, a[i] - i + 1));
    return dp[n];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }

    return 0;
}