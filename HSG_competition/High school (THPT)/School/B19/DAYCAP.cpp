#include <bits/stdc++.h>
using namespace std;
#define el "\n"
using ll = long long;

int n;
const int maxn = (int)1e5 + 5;
ll a[maxn];
ll k;

ll check(ll x){
    ll res = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < x) break;
        res += (a[i] / x);
    }
    return res;
}

int main(){
    freopen(".\\txt\\DAYCAP.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>a[i];

    ll l = 0, r = (ll)1e18;
    ll maxx = 0;

    while(l <= r){
        ll mid = l + (r - l)/2;
        ll res = check(mid);

        if(res >= k){
            maxx = max(maxx, mid);
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout<<maxx<<el;

    return 0;
}