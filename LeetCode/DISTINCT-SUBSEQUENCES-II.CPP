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
    int prev[26];
    memset(prev, 0, sizeof prev);

    int dp = 1;
    for(int i = 1; i <= n; i++){
        int x = s[i - 1] - 'a';
        int tmp = dp;
        dp = (dp * 2 % MOD - prev[x] + MOD) % MOD;
        prev[x] = tmp;
    }
    cout<<(dp - 1 + MOD) % MOD;
    return 0;
}