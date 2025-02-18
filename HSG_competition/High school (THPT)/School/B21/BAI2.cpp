#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;
const ll MOD = (ll)1e9 + 7;

ll factor(ll x){
    ll s = 1;
    for(int i = 2; i <= x; i++){
        s = (s * i) % MOD;
    }
    return s;
}

ll ppow(ll a, ll b){
    ll res = 1;
    while(b > 0){
        if(b % 2 == 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b/=2;
    }
    return res;
}

ll solve(string str){
    map<char, int> mp;
    int len = str.length();
    for(int i = 0; i < len; i++) mp[str[i]]++;

    ll s = 1;
    for(auto x : mp){
        s = (s * factor(x.second)) % MOD;
    }
    return factor(len) * ppow(s, MOD - 2) % MOD - 1;
}

int main(){
    freopen(".\\txt\\BAI2.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cin.ignore();

    for(int i = 0; i < n - 1; i++){
        string str;
        getline(cin, str);
        cout<<solve(str)<<el;
    }
    string str;
    getline(cin, str);
    cout<<solve(str);

    return 0;
}