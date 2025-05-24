#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, q;
const int maxn = 1e5 + 5;
const ll oo = LLONG_MAX;
ll a[maxn * 4] = {0}, lazy[4 * maxn] = {0};

void push(int i){
    if(lazy[i]){
        a[2 * i] += lazy[i];
        a[2 * i + 1] += lazy[i];
        lazy[2 * i] += lazy[i];
        lazy[2 * i + 1] += lazy[i];
        lazy[i] = 0;
    }
    return;
}

void update(int i, int st, int en, int l, int r, ll val){
    if(st > r || en < l) return;
    if(st >= l && en <= r){
        a[i] += val;
        lazy[i] += val;
        return;
    }
    int mid = (st + en) / 2;
    push(i);

    update(i * 2, st, mid, l, r, val);
    update(i * 2 + 1, mid + 1, en, l, r, val);

    a[i] = max(a[2 * i], a[2 * i + 1]);
    return;
}

ll query(int i, int st, int en, int l, int r){
    if(st > r || en < l) return -oo;
    if(st >= l && en <= r) return a[i];

    int mid = (st + en) / 2;
    push(i);
    
    return max(query(i * 2, st, mid, l, r), query(i * 2 + 1, mid + 1, en, l, r));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i <= n; i++){
        ll x;
        cin>>x;
        update(1, 1, n, i, i, x);
    }

    cin>>q;
    int opt, l, r;

    while(q--){
        cin>>opt>>l>>r;
        
        if(opt == 1){
            ll val;
            cin>>val;
            update(1, 1, n, l, r, val);
        }
        else cout<<query(1, 1, n, l, r)<<el;
    }
    return 0;
}