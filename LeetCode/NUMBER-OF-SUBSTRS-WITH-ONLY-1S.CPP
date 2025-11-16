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

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;

    int n = s.length();
    int len = 0;
    ll res = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == '1') len++;
        else {
            res = (res + 1LL * len * (len + 1) / 2) % MOD;
            len = 0;
        }
    }
    cout<<(int)(res + len * (len + 1) / 2) % MOD;
    return 0;
}