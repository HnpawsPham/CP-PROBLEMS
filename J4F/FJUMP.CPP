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
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    // ll dp[n + 1];
    // dp[1] = dp[0] = 0;
    // const ll oo = 1e16 + 5;

    // for(int i = 2; i <= n; i++){
    //     dp[i] = oo;
    //     for(int j = 1; j < i; j++){
    //         if(j + a[j] >= i)
    //             dp[i] = min(dp[i], dp[j] + 1);
    //     }
    // }
    // cout<<dp[n];

    ll maxx = 0, en = 1;
    int cnt = 0;
    for(int i = 1; i < n; i++){
        maxx = max(maxx, 1LL * i + 1LL * a[i]);

        if(i == en){
            en = maxx;
            cnt++;
            if(en >= 1LL * n) break;
        }
    }
    cout<<cnt;
    return 0;
}