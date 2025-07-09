#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

const ll MOD = 1e9 + 7;

// pow k mod
// ll ppow(ll a, int b){
//     if(b == 0) return 1;
//     ll half = ppow(a, b >> 1);
    
//     if(b & 1) return 1LL * half * half * a;
//     return 1LL * half * half;
// }

// pow co mod
ll ppow(ll a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b >> 1);
    
    if(b & 1) return 1LL * half * half % MOD * a % MOD;
    return 1LL * half * half % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll a, b;
    cin>>a>>b;
    cout<<ppow(a, b);

    return 0;
}