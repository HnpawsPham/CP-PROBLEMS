#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

struct node{
    ll w = 1;
    int cntp[5];

    node(){
        memset(cntp, 0, sizeof cntp);
    }
};

int n, k, m;
const int maxn = 1e5 + 5;
node t[maxn * 4];

node merge(const node& l, const node& r){
    node res;
    res.w = l.w * r.w % k;
    
    for(int i = 0; i < k; i++)
        res.cntp[i] = l.cntp[i];

    for(int i = 0; i < k; i++)
        res.cntp[l.w * i % k] += r.cntp[i];
    return res;
}

void build(int i, int l, int r, const vi& a){
    if(l == r){
        t[i].w = a[l - 1] % k;
        t[i].cntp[a[l - 1] % k] = 1;
        return;
    }

    int mid = (l+ r) / 2;
    build(2 * i, l, mid, a);
    build(2 * i + 1, mid + 1, r, a);
    t[i] = merge(t[2 * i], t[2 * i + 1]);
}

void update(int i, int l, int r, int pos, int val){
    if(l == r){
        t[i].w = val % k;
        memset(t[i].cntp, 0, sizeof t[i].cntp);
        t[i].cntp[val % k] = 1;
        return;
    }

    int mid = (l + r) / 2;
    if(pos <= mid)
        update(2 * i, l, mid, pos, val);
    else update(2 * i + 1, mid + 1, r, pos, val);
    t[i] = merge(t[2 * i], t[2 * i + 1]);
}

node query(int i, int st, int en, int l, int r){
    if(st > r || en < l) return node();
    if(st >= l && en <= r) return t[i];
    
    int mid = (st + en) / 2;
    return merge(query(2 * i, st, mid, l, r), query(2 * i + 1, mid + 1, en, l, r));
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>m;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    memset(t, 0, sizeof t);

    vector<vi> q(m, vi(4));
    for(int i = 0; i < m; i++)
        cin>>q[i][0]>>q[i][1]>>q[i][2]>>q[i][3];

    build(1, 1, n, a);
    vi res;
    for(const vi& v : q){
        update(1, 1, n, v[0] + 1, v[1]);
        res.push_back(query(1, 1, n, v[2] + 1, n).cntp[v[3]]);
    }

    for(int x : res) cout<<x<<" ";
    return 0;
}

// 5 3 3
// 1 2 3 4 5
// 2 2 0 2
// 3 3 3 0
// 0 1 0 1