#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n = s.length();

    ll res = 0, sum = 0;
    for(int i = 0; i < n; i++){
        sum = (sum * 10LL + 1LL * (s[i] - '0') * (i + 1)) % MOD;
        res = (res + sum) % MOD;
    }
    cout<<res;
    return 0;
}