#include <iostream>
using ll = long long;
using namespace std;

ll n, k;

ll max(ll a, ll b){
    if(a > b) return a;
    return b;
}

ll min(ll a, ll b){
    if(a < b) return a;
    return b;
}

int main() {
    freopen("TOYS.INP","r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    if(k <= 2 || k >= 2 * n) return cout<<0, 0;

    ll l = max(1LL, k - n);
    ll r = min(k - 1, n);

    if(l <= r) return cout<<(r - l + 1) / 2, 0;
}