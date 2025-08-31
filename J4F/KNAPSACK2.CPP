#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int v = 1e5 + 3;
const ll oo = 1e18;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, w;
    cin>>n>>w;
    pii a[n];
    for(int i = 0; i < n; i++) cin>>a[i].fi>>a[i].se;

    ll dp[v];
    dp[0] = 0;
    for(int i = 1; i < v; i++) dp[i] = oo;

    for(int i = 0; i < n; i++)
        for(int j = v - 1; j >= 0; j--){
            if(dp[j] + a[i].fi <= w)
                dp[j + a[i].se] = min(dp[j] + a[i].fi, dp[j + a[i].se]);
        }

    for(int i = v - 1; i >= 0; i--) 
        if(dp[i] != oo) {
            cout<<i;
            break;
        }
    return 0;
}