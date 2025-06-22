#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, k;
const int oo = 1e4 + 5;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k; 
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    if(k == 0) return cout<<0, 0;
    vector<int> dp(k + 1, oo);
    dp[0] = 0;

    for(int i = 0; i < n; i++)
        for(int j = a[i]; j <= k; j++)
            dp[j] = min(dp[j], dp[j - a[i]] + 1);
        
    cout<<(dp[k] != oo ? dp[k] : -1);
    return 0;
}