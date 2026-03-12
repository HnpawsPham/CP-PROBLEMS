#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin>>n>>s;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    int dp[s + 1];
    memset(dp, -1, sizeof dp);

    int res = n + 5;
    for(int i = 1; i <= n; i++){
        if(a[i] > s) continue;
        
        for(int j = s; j >= a[i]; j--)
            if(dp[j - a[i]] != -1) dp[j] = max(dp[j], dp[j - a[i]]);
        
        dp[a[i]] = i;
        if(dp[s] != -1) res = min(res, i - dp[s] + 1);
    }
    cout<<(res == n + 5 ? -1 : res);
    return 0;
}

// 10 100
// 14 33 22 21 11 5 13 28 61 2