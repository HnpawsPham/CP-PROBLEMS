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

int n, m;
const int maxn = 5e4 + 5;
ll t[4 * maxn] = {0}, lazy[4 * maxn];

void push(int i){
    if(!lazy[i]) return;
    t[2 * i] += lazy[i];
    t[2 * i + 1] += lazy[i];
    lazy[2 * i] += lazy[i];
    lazy[2 * i + 1] += lazy[i];
    lazy[i] = 0;
    return;
}

void update(int i, int st, int en, int l, int r, int val){
    if(en < l || st > r) return;
    if(st >= l && en <= r){
        t[i] += val;
        lazy[i] += val;
        return;
    }

    push(i);
    int mid = (st + en) / 2;
    update(2 * i, st, mid, l, r, val);
    update(2 * i + 1, mid + 1, en, l, r, val);

    t[i] = max(t[2 * i], t[2 * i + 1]);
    return;
}

int query(int i, int st, int en, int l, int r){
    if(en < l || st > r) return 0;
    if(st >= l && en <= r) return t[i];

    push(i);
    int mid = (st + en) / 2;
    return max(query(2 * i, st, mid, l, r), query(2 * i + 1, mid + 1, en, l, r));
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    while(m--){
        int opt, x, y, k;
        cin>>opt>>x>>y;
        if(opt == 0){
            cin>>k;
            update(1, 1, n, x, y, k);
        }
        else cout<<query(1, 1, n, x, y)<<el;
    }
    return 0;
}