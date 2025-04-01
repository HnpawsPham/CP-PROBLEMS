#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n + 1][2];
    for(int i = 1; i <= n; i++) cin>>a[i][0]>>a[i][1];

    ll dp[n + 1];
    dp[0] = 0;

    for(int i = n; i > 0; i--){
        int next = i + a[i][1] + 1;

        if(next <= n) dp[i] = dp[next] + a[i][0];
        else dp[i] = a[i][0];

        if(i < n) dp[i] = max(dp[i], dp[i + 1]);
    }
    cout<<dp[1];

    return 0;
}