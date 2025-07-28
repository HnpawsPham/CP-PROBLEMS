#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define ms multiset<int>
#pragma GCC optimize("O2,Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")

int n, q;
const int maxn = 1e5 + 2;
const int oo = 1e9 + 5;
vector<ms> t(maxn * 4);
vi a(maxn);

void build(int i, int l, int r){
    if(l == r){
        t[i].insert(a[l]);
        return;
    }

    int mid = (l + r) / 2;
    build(i * 2, l, mid);
    build(i * 2 + 1, mid + 1, r);

    t[i].insert(t[2 * i].begin(), t[2 * i].end());
    t[i].insert(t[2 * i + 1].begin(), t[2 * i + 1].end());
    return;
}

void update(int i, int pos, int l, int r, int old, int val){
    if(t[i].find(old) != t[i].end())
        t[i].erase(t[i].find(old));

    t[i].insert(val);

    if(l == r) return;

    int mid = (l + r) / 2;
    if(pos <= mid) update(i * 2, pos, l, mid, old, val);
    else update(i * 2 + 1, pos, mid + 1, r, old, val);
    return;
}

int get(int i, int st, int en, int l, int r, int k){
    if(st > r || en < l) return oo;
    if(st >= l && en <= r){
        auto it = t[i].lower_bound(k);
        if(it == t[i].end()) return oo;
        return *it;
    }
    
    int mid = (st + en) / 2;
    int ql = get(i * 2, st, mid, l, r, k);
    int qr = get(i * 2 + 1, mid + 1, en, l, r, k);
    return min(ql, qr);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i = 1; i <= n; i++) cin>>a[i];
    build(1, 1, n);

    int opt;
    while(q--){
        cin>>opt;
        if(opt == 1){
            int i, val;
            cin>>i>>val;
            update(1, i, 1, n, a[i], val);
            a[i] = val;
        }
        else{
            int l, r, k;
            cin>>l>>r>>k;
            int res = get(1, 1, n, l, r, k);
            cout<<(res == oo ? -1 : res)<<el;
        }
    }
    return 0;
}

// 5 4
// 1 5 3 4 5
// 2 1 3 2
// 2 3 5 6
// 1 2 2
// 2 1 5 2