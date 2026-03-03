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
#define taskname "MUAVE"

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n + 1], w[n];
    memset(a, 0, sizeof a);
    memset(w, 0, sizeof w);

    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i < n; i++) cin>>w[i];

    const int oo = 5e7 + 5;
    vi dp(n + 1, oo);
    dp[0] = 0;

    vi res;
    for(int i = 1; i <= n; i++){
        if(dp[i - 1] + a[i] < dp[i])
            dp[i] = dp[i - 1] + a[i];
  
        if(i > 1 && dp[i - 2] + w[i - 1] < dp[i]){
            dp[i] = dp[i - 2] + w[i - 1];
            res.push_back(i);
        }
    }

    cout<<dp[n]<<el;
    for(int x : res) cout<<x<<" ";
    return 0;
}

// 5
// 2 5 7 8 4
// 3 9 10 10