#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'

struct Node{
    ll maxx, pre, suf, sum;

    Node() {}
    Node(ll x) : maxx(x), pre(x), suf(x), sum(x) {}
    Node(ll maxx1, ll pre1, ll suf1, ll sum1) : 
        maxx(maxx1), pre(pre1), suf(suf1), sum(sum1) {}
};

int n, q;
const int maxn = 5e4 + 3;
const ll oo = 1e18;
Node a[maxn * 4];
int b[maxn];

Node combine(const Node& l, const Node& r){
    Node res;
    res.sum = l.sum + r.sum;
    res.pre = max(l.pre, l.sum + r.pre);
    res.suf = max(r.suf, r.sum + l.suf);
    res.maxx = max({l.suf + r.pre, l.maxx, r.maxx});

    return res;
}

void build(int i, int l, int r){
    if(l == r){
        a[i] = Node(b[l]);
        return;
    }

    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    a[i] = combine(a[2 * i], a[2 * i + 1]);
    return;
}

Node query(int i, int st, int en, int l, int r){
    if(st > r || en < l) return Node(-oo, -oo, -oo, 0);
    if(st >= l && en <= r) return a[i];

    int mid = (st + en) / 2;
    Node ql = query(i * 2, st, mid, l, r);
    Node qr = query(i * 2 + 1, mid + 1, en, l, r);

    return combine(ql, qr);
}   

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>b[i];
    build(1, 1, n);

    cin>>q;
    int x, y;
    while(q--){
        cin>>x>>y;
        cout<<query(1, 1, n, x, y).maxx<<el;
    }

    return 0;
}