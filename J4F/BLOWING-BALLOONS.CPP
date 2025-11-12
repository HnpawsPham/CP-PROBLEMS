#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, ll>
#define fi first
#define se second

int tc = 1;
bool comp(const pii& a, const pii& b){
    return a.fi + a.se > b.fi + b.se;
}

ll sol(){
    int n;
    cin>>n;
    pii a[n];
    for(int i = 0; i < n; i++) cin>>a[i].fi>>a[i].se;
    sort(a, a + n, comp);

    ll t = 0, res = 0;
    for(int i = 0; i < n; i++){
        int d = a[i].fi - t;
        if(d > 0) a[i].se += d;

        t = max(t, (ll)a[i].fi);
        res += 1LL * a[i].se * a[i].se;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}

// 2
// 3
// 3 2
// 1 4
// 2 3
// 2
// 5 0
// 1 3