#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    
    int dp[n];
    dp[0] = a[0];
    dp[1] = a[1];

    for(int i = 2; i < n; i++)
        dp[i] = min(dp[i - 1], dp[i - 2]) + a[i];
    
    cout<< min(dp[n - 1], dp[n - 2]);
    return 0;
}