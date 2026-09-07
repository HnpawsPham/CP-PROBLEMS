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

    string s;
    cin>>s;

    const int MOD = 1e9 + 7;
    int n = s.length();
    
    int dp[n + 1], prev[2] = {-1, -1};
    memset(dp, 0, sizeof dp);

    dp[0] = 1;
    bool has0 = 0;
    for(int i = 1; i <= n; i++){
        int x = s[i - 1] - '0'; 
        if(x == 0) has0 = 1;

        if(prev[1] == -1 && !x)
            dp[i] = dp[i - 1];
        else{
            dp[i] = ((dp[i - 1] * 2 % MOD) - !x + MOD) % MOD;
            if(prev[x] != -1)
                dp[i] = (dp[i] - (dp[prev[x]] - !x + MOD) % MOD + MOD) % MOD;
        }
        prev[x] = i - 1;
    }
    cout<<((dp[n] + has0) % MOD - 1 + MOD) % MOD;
    return 0;
}