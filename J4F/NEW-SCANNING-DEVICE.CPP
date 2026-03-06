#include <bits/stdc++.h>
using namespace std;
using db = double;
using ll = long long;
#define el endl
#define vi vector<ll>
#define pii pair<ll, ll>
#define fi first
#define se second
//#define taskname ""

const ll n = 1e9;
ll base, sti, stj, eni, enj;

ll ask(ll a, ll b, ll c, ll d){
    cout<<"? "<<a<<" "<<b<<" "<<c<<" "<<d<<el;

    ll x;
    cin>>x;
    if(x == -1) exit(0);
    return x;
}

ll scan(ll from, bool row){
    ll l = from, r = n, mid, x, res = n;
    while(l <= r){
        mid = (l + r) / 2;

        ll x;
        if(row) x = ask(1, 1, mid, n);
        else x = ask(1, 1, n, mid);

        if(x > 0){
            r = mid - 1;
            res = mid;
        }
        else l = mid + 1;
    }
    return res;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    base = ask(1, 1, n, n); 

    sti = scan(1, 1);
    stj = scan(1, 0);

    ll h, w;
    h = max(1LL, ask(sti, stj, n, stj));
    w = base / h;

    cout<<"! "<<sti<<" "<<stj<<" "<<sti + h - 1<<" "<<stj + w - 1<<el;
    return 0;
}