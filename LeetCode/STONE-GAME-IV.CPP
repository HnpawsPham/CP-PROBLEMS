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
    bool dp[n + 1];
    memset(dp, 0, sizeof dp);
    
    for(int i = n - 1; i >= 0; i--){
        for(int j = 1; i + j * j <= n && !dp[i]; j++)
            dp[i] |= !dp[i + j * j];
    }
    cout<<dp[0];
    return 0;
}