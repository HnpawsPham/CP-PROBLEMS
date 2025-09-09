#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int rev(int x, int sz) {
    int rx = 0;
    for (int i = 0; i < sz; ++i) 
        if ((x >> i) & 1) 
            rx |= 1 << (sz - 1 - i); 
    
    return rx;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    int m = 1 << n;
    ll q = k / m;

    ll x = 1 - (k % m == 0);

    vector<ll> res(m);
    for (int i = 0; i < m; ++i) {
        int tmp = rev(i, n);
        if (tmp < k % m) res[i] = q + 1;
        else res[i] = q;
    }

    cout<<x<<el;
    for(ll t : res) cout<<t<<" ";
    return 0;
}