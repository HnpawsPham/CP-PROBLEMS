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
const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7;
ll t[maxn * 4], mul[4 * maxn], add[4 * maxn], assign[4 * maxn];
int a[maxn];

void build(int i, int l, int r){
    if(l == r){
        t[i] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    t[i] = (t[2 * i] + t[2 * i + 1]) % MOD;
    return;
}

void multiply(int i, int l, int r, ll val){
    t[i] = t[i] * val % MOD;
    
    if(assign[i] != -1) assign[i] = assign[i] * val % MOD;
    else{
        mul[i] = mul[i] * val % MOD;
        add[i] = add[i] * val % MOD;
    }
    return;
}

void addition(int i, int l, int r, ll val){
    t[i] = (t[i] + val * (r - l + 1)) % MOD;

    if(assign[i] != -1) assign[i] = (assign[i] + val) % MOD;
    else add[i] = (add[i] + val) % MOD;
    return;
}

void init(int i, int l, int r, ll val){
    t[i] = val * (r - l + 1) % MOD;
    assign[i] = val;
    add[i] = 0;
    mul[i] = 1;
    return;
}

void push(int i, int l, int r){
    if(l == r) return;
    int mid = (l + r) / 2;

    if(assign[i] != -1){
        init(2 * i, l, mid, assign[i]);
        init(2 * i + 1, mid + 1, r, assign[i]);
        assign[i] = -1;
    }
    if(mul[i] != 1){
        multiply(2 * i, l, mid, mul[i]);
        multiply(2 * i + 1, mid + 1, r, mul[i]);
        mul[i] = 1;
    }
    if(add[i]){
        addition(2 * i, l, mid, add[i]);
        addition(2 * i + 1, mid + 1, r, add[i]);
        add[i] = 0;
    }
    return;
}

void update(int i, int st, int en, int l, int r, ll val, int type){
    if(st > r || en < l) return;
    if(st >= l && en <= r){
        if(type == 1) addition(i, st, en, val);
        else if(type == 2) multiply(i, st, en, val);
        else init(i, st, en, val);
        return;
    }

    push(i, st, en);
    int mid = (st + en) / 2;
    update(2 * i, st, mid, l, r, val, type);
    update(2 * i + 1, mid + 1, en, l, r, val, type);
    t[i] = (t[2 * i] + t[2 * i + 1]) % MOD;
    return;
}

ll query(int i, int st, int en, int l, int r){
    if(st > r || en < l) return 0;
    if(st >= l && en <= r) return t[i];

    push(i, st, en);
    int mid = (st + en) / 2;
    return (query(2 * i, st, mid, l, r) + query(2 * i + 1, mid + 1, en, l, r)) % MOD;
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
    for(int i = 1; i <= n; i++) cin>>a[i];
    build(1, 1, n);
    memset(add, 0, sizeof add);
    memset(assign, -1, sizeof assign);
    for(int i = 0; i < 4 * maxn; i++)
        mul[i] = 1;

    while(m--){
        int type, l, r;
        cin>>type>>l>>r;

        if(type == 4) cout<<query(1, 1, n, l, r)<<el;
        else{
            ll x;
            cin>>x;
            update(1, 1, n, l, r, x, type);
        }
    }
    return 0;
}