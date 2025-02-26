#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define MOD 123456789

ll n;

ll ppow(ll a, ll b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);
    if(b % 2 == 0) return (half * half) % MOD;
    return (half * half * a) % MOD;
}

int main(){
    freopen("COUNT.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    cout<<ppow(2, n - 1);

    return 0;
}