#include <bits/stdc++.h>
using namespace std;
#define el '\n'

const int oo = 1e9 + 2;
const int maxn = 1e5 + 2;
int n, q;
int t[maxn * 4], a[maxn];

// void build(int i, int l, int r){
//     if(l == r){
//         t[i] = a[l];
//         return;
//     }

//     int mid = (l + r) / 2;
//     build(i * 2, l, mid);
//     build(i * 2 + 1, mid + 1, r);
//     t[i] = max(t[2 * i], t[2 * i + 1]);

//     return; 
// }

void update(int i, int st, int en, int l, int r, int val){
    if(st > r || en < l) return;
    if(st >= l && en <= r){
        t[i] = val;
        return;
    }

    int mid = (st + en) / 2;
    update(i * 2, st, mid, l, r, val);
    update(i * 2 + 1, mid + 1, en, l, r, val);
    t[i] = max(t[2 * i], t[2 * i + 1]);
    return;
}

int query(int i, int st, int en, int l, int r){
    if(st > r || en < l) return -oo;
    if(st >= l && en <= r) return t[i];

    int mid = (st + en) / 2;
    return max(query(i * 2, st, mid, l, r), query(i * 2 + 1, mid + 1, en, l, r));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        update(1, 1, n, i, i, a[i]);
    }
    // build(1, 1, n);

    cin>>q;
    while(q--){
        int opt, u, v;
        cin>>opt>>u>>v;
        
        if(opt == 1) update(1, 1, n, u, u, v);
        else cout<<query(1, 1, n, u, v)<<el;
    }

    return 0;
}

// 5
// 1 4 2 3 5
// 6
// 2 1 3
// 1 3 3
// 2 1 5
// 2 3 5
// 1 2 3
// 2 2 4
