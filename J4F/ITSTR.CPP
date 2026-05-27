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
    ll val;
    int sz;
    node() {};
    node(ll val1, int sz1) : val(val1), sz(sz1) {};
};

int n, m;
string s;
const int maxn = 1e5 + 5;
const ll MOD = 1007050321;
node t[maxn * 4];
int bit[maxn] = {0};
ll pow2[maxn];

void compute(){
    pow2[0] = 1;
    for(int i = 1; i < maxn; i++)
        pow2[i] = pow2[i - 1] * 2 % MOD;
    return;
}

void add(int i, int val){
    while(i <= n){
        bit[i] += val;
        i += (i & -i);
    }
    return;
}

int get(int i){
    int res = 0;
    while(i > 0){
        res += bit[i];
        i -= (i & -i);
    }
    return res;
}

int find(int pos){
    int l = 1, r = n, mid;
    while(l <= r){
        mid = (l + r) / 2;
        if(get(mid) >= pos)
            r = mid - 1;
        else l = mid + 1;
    }
    return l;
}

void build(int i, int l, int r){
    if(l == r){
        t[i].val = s[l] - '0';
        t[i].sz = 1;
        return;
    }

    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    t[i].val = (t[2 * i].val * pow2[t[2 * i + 1].sz] % MOD + t[2 * i + 1].val) % MOD;
    t[i].sz = t[2 * i].sz + t[2 * i + 1].sz;
    return;
}

void update(int i, int l, int r, int pos){
    if(l == r){
        t[i].val = t[i].sz = 0;
        return;
    }

    int mid = (l + r) / 2;
    if(pos <= mid) update(2 * i, l, mid, pos);
    else update(2 * i + 1, mid + 1, r, pos);

    t[i].val = (t[2 * i].val * pow2[t[2 * i + 1].sz] % MOD + t[2 * i + 1].val) % MOD;
    t[i].sz = t[2 * i].sz + t[2 * i + 1].sz;
    return;
}

node query(int i, int st, int en, int l, int r){
    if(st > r || en < l) return node(0, 0);
    if(st >= l && en <= r) return t[i];

    int mid = (st + en) / 2;
    node left = query(2 * i, st, mid, l, r);
    node right = query(2 * i + 1, mid + 1, en, l, r);

    node res;
    res.val = (left.val * pow2[right.sz] % MOD + right.val) % MOD;
    res.sz = left.sz + right.sz;
    return res;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>m;
    n = s.length();
    s = '.' + s;

    compute();
    build(1, 1, n);
    for(int i = 1; i < maxn; i++)
        add(i, 1);

    while(m--){
        char opt;
        cin>>opt;
        if(opt == '-'){
            int pos;
            cin>>pos;
            pos = find(pos);
            add(pos, -1);
            update(1, 1, n, pos);
        }
        else{
            int l, r;
            cin>>l>>r;
            l = find(l);
            r = find(r);
            cout<<query(1, 1, n, l, r).val<<el;
        }
    }
    return 0;
}