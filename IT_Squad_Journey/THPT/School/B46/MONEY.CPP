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
#define taskname "MONEY"

int n, m;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    ll dp[m + 1] = {0};
    dp[0] = 1;

    for(int i = 0; i < n; i++)
        for(int j = m; j >= a[i]; j--){
            if(j < a[i]) continue;
            dp[j] += dp[j - a[i]];
        }
    cout<<dp[m];
    return 0;
}