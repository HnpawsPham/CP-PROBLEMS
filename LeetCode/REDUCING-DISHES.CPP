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

    int n;
    cin>>n;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    
    sort(a.begin(), a.end());
    const int oo = 1e7 + 5;
    vector<vi> dp(n, vi(n + 1, -oo));
    for(int i = 0; i < n; i++)
        dp[i][1] = a[i];

    for(int i = 0; i < n; i++)
        for(int k = 1; k <= n; k++)
            dp[i][k] = max(dp[i][k], dp[i - 1][k - 1] + a[i] * k);
        
    cout<<*max_element(dp[n - 1].begin(), dp[n - 1].end());
    return 0;
}

// 5
// -1 -8 0 5 -9