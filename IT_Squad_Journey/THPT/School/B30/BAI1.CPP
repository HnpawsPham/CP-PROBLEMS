#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define el "\n"
#define MOD 2023

ll n;

int main(){
    freopen("BAI1.INP", "r", stdin);
    freopen("BAI1.OUT", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    n %= MOD;
    ll target = ((3 * n - 1) + 2) % MOD, res;

    if(n % 2 == 0) res = (target * n / 2) % MOD;
    else res = ((target * n) * (MOD + 1) / 2) % MOD;
    cout<<res;
    return 0;
}
