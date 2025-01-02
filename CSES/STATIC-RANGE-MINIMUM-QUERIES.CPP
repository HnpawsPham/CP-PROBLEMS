#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, q, node;
const int maxn = 2 * (int)1e5 + 5;
ll a[maxn * 4];

ll min(ll a, ll b){
    if(a < b) return a;
    return b;
}

void build(){
    for(int i = node - 1; i > 0; i--) a[i] = min(a[2 * i], a[2 * i + 1]);
    return;
}

ll get(int l, int r){
    ll res = LLONG_MAX;
    l += node;
    r += node;

    while(l <= r){
        if(l % 2 == 1){
            res = min(res, a[l]);
            l++;
        }
        if(r % 2 == 0){
            res = min(res, a[r]);
            r--;
        }
        l /= 2;
        r /= 2;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    node = n + (n % 2);
    for(int i = 0; i < n; i++) cin>>a[i + node];

    build();

    while(q--){
        int l, r;
        cin>>l>>r;
        cout<<get(l - 1, r - 1)<<el;
    }

    return 0;
}