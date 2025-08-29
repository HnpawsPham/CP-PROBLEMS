#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int v1, v2, n, d;
    cin>>v1>>v2>>n>>d;

    int dp[n] = {0};
    if(v1 > v2) swap(v1, v2);
    dp[0] = v1;
    dp[n - 1] = v2;
    for(int i = 1; i < n - 1; i++)
        dp[i] = min(dp[i - 1] + d, v2 + d * (n - i - 1));
    
    cout<<accumulate(dp, dp + n, 0);
    return 0;
}