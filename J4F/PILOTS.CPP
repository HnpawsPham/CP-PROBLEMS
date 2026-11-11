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
    pii a[n];
    for(int i = 0; i < n; i++)
        cin>>a[i].fi>>a[i].se;

    int const oo = 1e9 + 15;
    vi dp(n / 2 + 1, oo);
    dp[0] = 0;

    for(int i = 0; i < n; i++){
        vi tmp(n / 2 + 1, oo);
        for(int j = 0; j <= (i + 1) / 2; j++){
            if(i - j >= j)
                tmp[j] = min(tmp[j], dp[j] + a[i].se);
            if(j > 0 && i - j + 1 >= j - 1)
                tmp[j] = min(tmp[j], dp[j - 1] + a[i].fi);
        }
        dp = tmp;
    }
    cout<<dp[n / 2];
    return 0;
}