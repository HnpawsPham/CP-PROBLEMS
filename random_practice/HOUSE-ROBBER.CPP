#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin>>a[i];

    int dp[n + 1];
    dp[1] = a[1];
    dp[0] = 0;
    int res = 0;

    for(int i = 2; i <= n; i++){
        dp[i] = 0;
        for(int j = 0; j < i - 1; j++)
            dp[i] = max(dp[i], dp[j] + a[i]);
        res = max(res, dp[i]);
    }
    cout<<res;
    return 0;
}