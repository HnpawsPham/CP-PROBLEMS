#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vector<vi> dp(n, vi(m, 1));

    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++)  
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    
    cout<<dp[n - 1][m - 1];
    return 0;
}