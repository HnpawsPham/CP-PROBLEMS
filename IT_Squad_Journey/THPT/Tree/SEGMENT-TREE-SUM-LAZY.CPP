#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, q;
const int MOD = 1e3 + 7;
const int maxn = 2e5 + 5;
ll a[maxn * 4] = {0}, lazy[maxn * 4] = {0};

void push(int i, int st, int en) {
    if (lazy[i]) {
        int mid = (st + en) / 2;
        int l = mid - st + 1;
        int r = en - mid;
        
        a[2 * i] += lazy[i] * l;
        a[2 * i + 1] += lazy[i] * r;
        lazy[2 * i] += lazy[i];
        lazy[2 * i + 1] += lazy[i];
        lazy[i] = 0;
    }
}

void update(int i, int st, int en, int l, int r, ll val){
    if(st > r || en < l) return;
    if(st >= l && en <= r){
        a[i] += val * (en - st + 1);
        lazy[i] += val;
        return;
    }

    int mid = (st + en) / 2;
    push(i, st, en);
    update(2 * i, st, mid, l, r, val);
    update(2 * i + 1, mid + 1, en, l, r, val);

    a[i] = a[2 * i] + a[2 * i + 1];
    return;
}

ll query(int i, int st, int en, int l, int r){
    if(st > r || en < l) return 0;
    if(st >= l && en <= r) return a[i];

    int mid = (st + en) / 2;
    push(i, st, en);

    return query(i * 2, st, mid, l, r) + query(i * 2 + 1, mid + 1, en, l, r);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    int opt, l, r;
    ll k;

    while(q--){
        cin>>opt>>l>>r;
        if(opt == 1) {
            cin>>k;
            update(1, 1, n, l, r, k);
        }
        else cout<<query(1, 1, n, l, r)<<el;
    }
    return 0;
}
