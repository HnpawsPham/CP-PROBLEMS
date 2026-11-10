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
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    const int oo = 1e9 + 5;
    int dp[n + 1];
    for(int i = 1; i <= n; i++)
        dp[i] = oo;
    dp[0] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= 3; j++){
            if(i - j < 0) break;
            dp[i] = min(dp[i], dp[i - j] + a[i - 1] + j * j);
        }
    cout<<dp[n];
    return 0;
}