#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, q, opt, l, r;
ll a, b;
const ll MOD = 1e9 + 7;
const ll INVMOD = (MOD + 1) / 2;

const int maxn = 1e5 + 5;
ll t[maxn * 4] = {0}, 
   lazy1[maxn * 4] = {0}, // A x i
   lazy2[maxn * 4] = {0}; // B - A x L

void calc(int i, int pos, ll wl, ll wr){
    t[pos] = (t[pos] + (lazy1[i] * wl % MOD) + (lazy2[i] * wr % MOD)) % MOD;
    lazy1[pos] = (lazy1[pos] + lazy1[i]) % MOD;
    lazy2[pos] = (lazy2[pos] + lazy2[i]) % MOD;
    return;
}

void push(int i, int st, int en){
    if(!lazy1[i] && !lazy2[i]) return;

    int mid = (st + en) / 2;
    int l = mid - st + 1;
    int r = en - mid;

    ll wl = (st + mid) % MOD * l % MOD * INVMOD % MOD;
    ll wr = (mid + 1 + en) % MOD * r % MOD * INVMOD % MOD;

    calc(i, 2 * i, wl, l);
    calc(i, 2 * i + 1, wr, r);

    lazy1[i] = lazy2[i] = 0;
    return;
}

void update(int i, int st, int en, int l, int r, ll wl, ll wr){
    if(st > r || en < l) return;
    if(st >= l && en <= r){
        ll ld = en - st + 1;
        ll rd = (st + en) % MOD * ld % MOD * INVMOD % MOD;

        t[i] = (t[i] + wr * ld % MOD) % MOD;
        t[i] =  (t[i] + wl * rd % MOD) % MOD;

        lazy1[i] = (lazy1[i] + wl) % MOD;
        lazy2[i] = (lazy2[i] + wr) % MOD;
        return;
    }

    int mid = (st + en) / 2;
    push(i, st, en);
    update(2 * i, st, mid, l, r, wl, wr);
    update(2 * i + 1, mid + 1, en, l, r, wl, wr);

    t[i] = (t[2 * i] + t[2 * i + 1]) % MOD;
    return;
}

ll query(int i, int st, int en, int l, int r){
    if(st > r || en < l) return 0;
    if(st >= l && en <= r) return t[i];

    int mid = (st + en) / 2;
    push(i, st, en);

    return (query(2 * i, st, mid, l, r) + query(2 * i + 1, mid + 1, en, l, r)) % MOD;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;

    while(q--){
        cin>>opt>>l>>r;
        if(opt == 1){
            cin>>a>>b;
            update(1, 1, n, l, r, a, (b - (a * l % MOD) + MOD) % MOD);
        }
        else cout<<query(1, 1, n, l, r)<<el;
    }

    return 0;
}

// 5 4
// 1 1 5 1 1
// 2 1 5
// 1 2 3 1 1
// 2 1 5

// 5 4
// 1 1 5 5456567545 9679607567
// 2 1 5
// 1 2 3 123785667 3456864574
// 2 1 5

