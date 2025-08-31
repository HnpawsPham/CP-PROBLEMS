#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, MOD;
const int maxn = 2e5 + 5;
ll fact[maxn];
int cnt2[maxn] = {0};

pii exp2(int x){
    int cnt = 0;
    while(x % 2 == 0) {
        x /= 2;
        cnt++;
    }
    return {x, cnt};
}

void calc_fact(){
    fact[0] = 1;
    for(int i = 1; i < maxn; i++){
        pii e2 = exp2(i);
        fact[i] = fact[i - 1] * e2.fi % MOD;
        cnt2[i] = cnt2[i - 1] + e2.se;
    }
    return;
}

ll ppow(int a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);
    if(b & 1) return half * half % MOD * a % MOD;
    return half * half % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n], b[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < n; i++) cin>>b[i];
    cin>>MOD;

    calc_fact();
    unordered_map<int, int> mp;
    int dup = 0;
    for(int i = 0; i < n; i++) {
        mp[a[i]]++;
        mp[b[i]]++;
        if(a[i] == b[i]) dup++;
    }

    ll res = 1;
    int sum = 0;
    for(auto x : mp){
        res = res * fact[x.se] % MOD;
        sum += cnt2[x.se];
    }
    res = res * ppow(2, sum - dup) % MOD;
    cout<<res;
    return 0;
}

// 2
// 1 2
// 2 2
// 4