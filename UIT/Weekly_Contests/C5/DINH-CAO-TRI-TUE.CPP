#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    ll dp[n + 3] = {0},
    p[n + 3] = {0}; 

    for(int i = 0; i < n + 3; i++){
        dp[i] = 0;
        p[i] = 0;
    }
    
    for (int i = n - 1; i >= 0; --i)
        p[i] = p[i + 1] + a[i];

    for (int i = n - 1; i >= 0; --i)
        dp[i] = p[i] - min(dp[i + 1], min(dp[i + 2], dp[i + 3]));

    cout<<dp[0];
    return 0;
}
