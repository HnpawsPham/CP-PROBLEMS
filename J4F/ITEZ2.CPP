#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, q;
const int maxn = 1e5 + 5;
ll a[4 * maxn] = {0};

void update(int i, int st, int en, int pos, int val){
    if(st == en){
        a[i] = val;
        return;
    }

    int mid = (st + en) / 2;
    
    if(pos <= mid) 
        update(2 * i, st, mid, pos, val);
    else 
        update(2 * i + 1, mid + 1, en, pos, val);

    a[i] = a[2 * i] + a[2 * i + 1];
    return;
}

ll query(int i, int st, int en, int l, int r){
    if(st > r || en < l) return 0;

    if(l <= st && r >= en)
        return a[i];

    int mid = (st + en) / 2;
    return query(2 * i, st, mid, l, r) + query(2 * i + 1, mid + 1, en, l, r);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    int k, x, y;

    while(q--){
        cin>>k>>x>>y;
        
        if(k == 1) update(1, 1, n, x, y);
        else cout<<query(1, 1, n, x, y)<<el;
    }

    return 0;
}