#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'

const int maxn = 2e5 + 5;
ll t[maxn * 4] = {0};

void update(int i, int st, int en, int l, int r, int val){
    if(st > r || en < l) return;
    if(st >= l && en <= r){
        t[i] = val;
        return;
    }

    int mid = (st + en) / 2;
    update(2 * i, st, mid, l, r, val);
    update(2 * i + 1, mid + 1, en, l, r, val);
    t[i] = t[2 * i] + t[2 * i + 1];
    
    return;
}

ll query(int i, int st, int en, int l, int r){
    if(st > r || en < l) return 0;
    if(st >= l && en <= r) return t[i];

    int mid = (st + en) / 2;
    return query(2 * i, st, mid, l, r) + query(2 * i + 1, mid + 1, en, l, r);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        update(1, 1, n, i, i, x);
    }

    int opt, x, y;
    while(q--){
        cin>>opt>>x>>y;
        if(opt == 1) update(1, 1, n, x, x, y);
        else cout<<query(1, 1, n, x, y)<<el;
    }
    return 0;
}