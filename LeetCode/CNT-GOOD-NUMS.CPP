#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define MOD 1000000007

ll n;

ll ppow(ll a, ll b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);

    if(b % 2) return (half * half * a) % MOD;
    else return (half * half) % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    ll oddpos = n / 2;
    ll evenpos = n - oddpos;

    ll res = (ppow(5, evenpos) * ppow(4, oddpos)) % MOD;
    cout<<res;
    return 0;
}
