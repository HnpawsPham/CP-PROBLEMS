#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>

const int maxn = 1e5 + 5;
vi t(maxn * 4);

void update(int i, int st, int en, int l, int r, int val){
    if(st > r || en < l) return;
    if(st >= l && en <= r){
        t[i] = val;
        return;
    }

    int mid = (st + en) / 2;
    update(2 * i, st, mid, l, r, val);
    update(2 * i + 1, mid + 1, en, l , r, val);
    t[i] = max(t[2 * i], t[2 * i + 1]);
    return;
}

int query(int i, int l, int r, int x){
    if(t[i] < x) return -1;
    if(l == r) return l;

    int mid = (l + r) / 2;
    int ql = query(2 * i, l, mid, x);
    
    if(ql != -1) return ql;
    return query(2 * i + 1, mid + 1, r, x);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vi a(n), b(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i< n; i++) cin>>b[i];

    for(int i = 0; i < n; i++)
        update(1, 1, n, i + 1, i + 1, b[i]);

    int cnt = 0;
    for(int x : a){
        int pos = query(1, 1, n, x);
        if(pos == -1) cnt++;
        else update(1, 1, n, pos, pos, INT_MIN);
    }
    cout<<cnt;
    return 0;
}

// 3
// 4 2 5
// 3 5 4

// 3
// 3 6 1
// 6 4 7