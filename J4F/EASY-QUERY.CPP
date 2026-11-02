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

int n, k;
const int maxn = 1e5 + 25;
int a[maxn];
ll t[maxn * 4], lazy[maxn * 4];

void push(int i, int l, int r, int mid){
    if(!lazy[i]) return;

    t[2 * i] += 1LL * (mid - l + 1) * lazy[i];
    t[2 * i + 1] += 1LL * (r - mid) * lazy[i];
    lazy[2 * i] += lazy[i];
    lazy[2 * i + 1] += lazy[i];
    lazy[i] = 0;
}

void build(int i, int l, int r){
    if(l == r){
        t[i] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    t[i] = t[2 * i] + t[2 * i + 1];
}

void update(int i, int st, int en, int l, int r, int val){
    if(st > r || en < l) return;
    if(st >= l && en <= r){
        t[i] += 1LL * (en - st + 1) * val;
        lazy[i] += val;
        return;
    }

    int mid = (st + en) / 2;
    push(i, st, en, mid);
    update(2 * i, st, mid, l, r, val);
    update(2 * i + 1, mid + 1, en, l, r, val);
    t[i] = t[2 * i] + t[2 * i + 1];
}

ll query(int i, int st, int en, int l, int r){
    if(st > r || en < l) return 0;
    if(st >= l && en <= r) return t[i];

    int mid = (st + en) / 2;
    push(i, st, en, mid);
    return query(2 * i, st, mid, l, r) + query(2 * i + 1, mid + 1, en, l, r);
}

struct que{
    int opt, l, r, x;
    void rev(){
        x = -x;
    } 
} q[maxn];


int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i = 1; i <= n; i++)
        cin>>a[i];

    memset(t, 0, sizeof t);
    memset(lazy, 0, sizeof lazy);
    build(1, 1, n);

    for(int i = 1; i <= k; i++){
        int opt;
        cin>>opt;
        if(opt == 1){
            int l, r, x;
            cin>>l>>r>>x;
            q[i] = {opt, l, r, x};
            update(1, 1, n, l, r, x);
        }
        else if(opt == 2){
            int pos;
            cin>>pos;
            q[pos].rev();
            q[i] = q[pos];
            update(1, 1, n, q[i].l, q[i].r, q[i].x);
        }
        else{
            int l, r;
            cin>>l>>r;
            cout<<query(1, 1, n, l, r)<<el;
        }
    }
    return 0;
}