#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    if(n < k * (k + 1)/2){
        cout<<0;
        return 0;
    }

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for(int i = 1; i<=n; i++) dp[i][1] = 1;

    for(int j = 2; j <= k; j++){
        for(int i = j; i <= n; i++)
            dp[i][j] = dp[i - j][j - 1] + dp[i - j][j];
        
    }
    cout<<dp[n][k];

    return 0;
}