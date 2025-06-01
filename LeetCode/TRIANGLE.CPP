#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int> 

const int oo = 1e8;
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vector<vi> a(n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j <= i; j++){
            int x;
            cin>>x;
            a[i].push_back(x);
        }
    
    vector<vi> dp(n, vi(n, oo));
    dp[0][0] = a[0][0];

    for(int i = 1; i < n; i++)
        for(int j = 0; j <= i; j++){
            if (j < i) 
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i][j]);

            if (j > 0) 
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a[i][j]);
        }

    int res = oo;
    for(int i = 0; i < n; i++) 
        res = min(res, dp[n - 1][i]);
    cout<<res;
    return 0;
}