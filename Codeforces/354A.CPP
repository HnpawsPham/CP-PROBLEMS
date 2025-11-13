#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second

int n, l, r, ql, qr;
const ll oo = 1e18;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>l>>r>>ql>>qr;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    int p[n + 1] = {0};
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i];

    ll res = oo;
    for(int i = 0; i <= n; i++){
        ll suml = 1LL * (p[i] - p[0]) * l;
        ll sumr = 1LL * (p[n] - p[i]) * r;

        ll d = 0;
        if(i > n - i) d = (2 * i - n - 1) * ql;
        else if(i < n - i) d = (n - 2 * i - 1) * qr;

        res = min(res, suml + sumr + max(0LL, d));
    }
    cout<<res;
    return 0;
}