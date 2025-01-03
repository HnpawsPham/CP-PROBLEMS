#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n";

int n, q, node;
const int maxn = 2 * (int)1e5 + 5;
ll a[maxn * 4];

void build(){
    for(int i = node - 1; i > 0; i--) a[i] = min(a[i * 2], a[i * 2 + 1]);
    return;
}

void update(int pos, ll val){
    pos += node;
    a[pos] = val;

    do{
        pos /= 2;
        a[pos] = min(a[pos * 2], a[pos * 2 + 1]);
    }
    while(pos > 0);
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
        r /= 2;
        l /= 2;
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
        int c;
        cin>>c;

        if(c == 1){
            int k; ll u;
            cin>>k>>u;
            update(k - 1, u);
        }
        else{
            int l, r;
            cin>>l>>r;
            cout<<get(l - 1, r - 1)<<el;
        }
    }

    return 0;
}