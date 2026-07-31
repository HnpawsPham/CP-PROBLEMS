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
    string s;
    cin>>n>>s;

    ll dp[n + 1] = {0}, p[n + 1];
    for(int i = 1; i <= n; i++)
        dp[i] = 1;

    for(int len = 2; len <= n; len++){
        p[0] = 0;
        for(int i = 1; i <= len - 1; i++)
            p[i] = (p[i - 1] + dp[i]) % MOD;

        for(int i = 1; i <= n; i++){
            if(s[len - 2] == '>')
                dp[i] = p[i - 1];
            else dp[i] = (p[len - 1] - p[i - 1] + MOD) % MOD;
        }
    }

    ll res = 0;
    for(int i = 1; i <= n; i++)
        res = (res + dp[i]) % MOD;
    cout<<res;
    return 0;
}