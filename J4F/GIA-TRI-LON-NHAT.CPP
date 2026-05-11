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
const int maxn = 5e4 + 2;
int t[maxn * 4] = {0}, lazy[maxn * 4] = {0};

void push(int i){
    if(!lazy[i]) return;
    lazy[2 * i] += lazy[i];
    lazy[2 * i+ 1] += lazy[i];
    t[2 * i] += lazy[i];
    t[2 * i + 1] += lazy[i];
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

    push(i);
    int mid = (st + en) / 2;

    update(2 * i, st, mid, l, r, val);
    update(2 * i + 1, mid + 1, en, l, r, val);
    t[i] = max(t[2 * i], t[2 * i + 1]);
    return;
}

ll query(int i, int st, int en, int l, int r){
    if(st > r || en < l) return -1;
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
        int l, r, w;
        cin>>l>>r>>w;
        update(1, 1, n, l, r, w);
    }

    int q;
    cin>>q;
    while(q--){
        int l, r;
        cin>>l>>r;
        cout<<query(1, 1, n, l, r)<<el;
    }
    return 0;
}