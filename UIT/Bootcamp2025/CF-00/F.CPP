#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second
#pragma GCC optimize("O2,unroll-loops,no-stack-protector")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

int calc(char open, char close) {
    if(open == '?' && close == '?') return 3;
    if(open == '?') {
        if(close == ')' || close == ']' || close == '}') return 1;
        return 0;
    }
    if(close == '?') {
        if(open == '(' || open == '[' || open == '{') return 1;
        return 0;
    }
    if(open == '(' && close == ')') return 1;
    if(open == '[' && close == ']') return 1;
    if(open == '{' && close == '}') return 1;
    return 0;
}

const int MOD = 1e5;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin>>n>>s;
    s = '-' + s;
    ll dp[205][205];

    for(int len = 2; len <= n; len++) {
        for(int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if((len % 2) != 0) continue; 

            ll res = 0;
            for(int k = l + 1; k <= r; k += 2) {
                int cnt = calc(s[l], s[k]);
                if(cnt > 0) {
                    ll left = (l + 1 <= k - 1 ? dp[l + 1][k - 1] : 1);
                    ll right = (k + 1 <= r ? dp[k + 1][r] : 1);
                    res += 1LL * cnt * left % MOD * right % MOD;
                }
            }
            dp[l][r] = res;
        }
    }
    cout << dp[1][n] % MOD;
    return 0;
}