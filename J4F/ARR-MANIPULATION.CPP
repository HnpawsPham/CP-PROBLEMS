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

int n, q;
const int maxn = 1e7 + 5;
ll t[maxn * 4] = {0}, lazy[maxn * 4] = {0};

void push(int i){
    if(!lazy[i]) return;
    t[i] += lazy[i];
    t[2 * i] += lazy[i];
    t[2 * i + 1] += lazy[i];
    lazy[2 * i] += lazy[i];
    lazy[2 * i + 1] += lazy[i];
    lazy[i] = 0;
    return;
}

void update(int i, int st, int en, int l, int r, int val){
    if(st > r || en < l) return;
    if(st >= l && en <= r){
        t[i] += val;
        lazy[i] += val;
        return;
    }

    int mid = (st + en) / 2;
    push(i);

    update(2 * i, st, mid, l, r, val);
    update(2 * i + 1, mid + 1, en, l, r, val);
    t[i] = max(t[2 * i], t[2 * i + 1]);
    return;
}

ll query(int i, int l, int r){
    if(l == r) return t[i];

    int mid = (l + r) / 2;
    return max(query(2 * i, l, mid), query(2 * i + 1, mid + 1, r));
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    if(n < maxn){
        for(const vi& v : que)
            update(1, 1, n, v[0], v[1], v[2]);
        return cout<<query(1, 1, n), 0;
    }
    
    vll d(n + 1, 0);
    for(const vi & v : que){
        d[v[0] - 1] += v[2];
        d[v[1]] -= v[2];
    }
    
    for(int i = 0; i <= n; i++)
        if(i > 0) d[i] += d[i - 1];
    cout<<*max_element(d.begin(), d.end());
    return 0;
}

// 5 3
// 1 2 100
// 2 5 100
// 3 4 100