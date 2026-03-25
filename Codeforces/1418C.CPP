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

int tc = 1;

int sol(){
    int n;
    cin>>n;
    int a[n + 2];
    for(int i = 1; i <= n; i++) cin>>a[i];

    const int oo = 4e5 + 4;
    int dp[n + 2][2];

    for(int i = 0; i <= n; i++)
        dp[i][0] = dp[i][1] = oo;

    dp[0][0] = 0;

    for(int i = 1; i <= n; i++){
        dp[i][1] = min(dp[i][1], dp[i - 1][0] + a[i]);
        if(i >= 2) dp[i][1] = min(dp[i][1], dp[i - 2][0] + a[i - 1] + a[i]);

        dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if(i >= 2) dp[i][0] = min(dp[i][0], dp[i - 2][1]);
    }
    return min(dp[n][0], dp[n][1]);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}

// 1
// 5
// 0 0 1 1 0