#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long int;
#define el "\n"

unordered_map<ll, ll> mp;

ll sol(ll n){
    if(n <= 2) return n;

    ll a = n / 2;
    ll b = n / 3;
    ll c = n / 4;

    if(mp[a]) a = mp[a];
    else a = sol(a);

    if(mp[b]) b = mp[b];
    else b = sol(b);

    if(mp[c]) c = mp[c];
    else c = sol(c);
    
    return mp[n] = max(n, a + b + c);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;

    while(cin>>n)
        cout<<sol(n)<<el;

    return 0;
}
