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

void sol(){
    int n;
    cin>>n;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    int p[n + 1] = {0}, s[n + 1];
    s[n] = a[n];
    for(int i = 1; i <= n; i++)
        p[i] = max(p[i - 1], a[i]);

    for(int i = n - 1; i > 0; i--)
        s[i] = min(s[i + 1], a[i]);

    int dp[n + 1];
    dp[n] = p[n];

    for(int i = n - 1; i > 0; i--){
        dp[i] = p[i];
        if(s[i + 1] < dp[i]) dp[i] = max(dp[i], dp[i + 1]);
    }
    for(int i = 1; i <= n; i++) cout<<dp[i]<<" ";
    cout<<el;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        sol();
    }

    return 0;
}