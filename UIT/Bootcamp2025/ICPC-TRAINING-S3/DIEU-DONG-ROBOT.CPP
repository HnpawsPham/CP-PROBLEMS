#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<ll, int>
#define fi first
#define se second

int n, q;

bool check(int i){
    if(i < 1 || i > n) return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    pii a[n + 1];
    a[0] = {LLONG_MAX, INT_MAX};
    for(int i = 1; i <= n; i++) {
        cin>>a[i].fi;
        a[i].se = i;
    }
    sort(a + 1, a + n + 1);

    cin>>q;
    while(q--){
        ll x;
        cin>>x;

        pii cur = {x, 0};
        int x1 = lower_bound(a + 1, a + n + 1, cur) - a - 1;
        int x2 = lower_bound(a + 1, a + n + 1, cur) - a;

        if(!check(x1)) {
            cur = a[x2];
            a[x2].fi = x;
        }
        else if(!check(x2)) {
            cur = a[x1];
            a[x1].fi = x;
        }
        else {
            ll d1 = abs(x - a[x1].fi);
            ll d2 = abs(x - a[x2].fi);

            if(d1 < d2 || (d1 == d2 && a[x1].se < a[x2].se)){
                cur = a[x1];
                a[x1].fi = x;
            }
            else{
                cur = a[x2];
                a[x2].fi = x;
            }
        }
        cout<<(cur.se == INT_MAX ? -1 : cur.se)<<el;
    }
    return 0;
}