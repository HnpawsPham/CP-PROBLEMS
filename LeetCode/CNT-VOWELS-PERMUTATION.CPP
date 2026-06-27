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

vector<int> mp[5] = {
    {1, 2, 4}, //a
    {0, 2}, // e
    {1, 3}, // u
    {2}, // i
    {2, 3} //o
};

const int MOD = 1e9 + 7;

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
    int dp[n][5];
    memset(dp, 0, sizeof dp);

    for(int i = 0; i < 5; i++)
        dp[0][i] = 1;

    for(int i = 1; i < n; i++)
        for(int j = 0; j < 5; j++){
            for(int x : mp[j])
                dp[i][j] = (dp[i][j] + dp[i - 1][x]) % MOD;
        }
    
    int res = 0;
    for(int i = 0; i < 5; i++)
        res = (res + dp[n - 1][i]) % MOD;
    cout<<res;
    return 0;
}