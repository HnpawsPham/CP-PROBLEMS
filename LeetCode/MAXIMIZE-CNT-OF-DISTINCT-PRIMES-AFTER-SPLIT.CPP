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
const int maxp = 1e6 + 5;
const int maxn = 1e5 + 5;
bitset<maxp> nprime;
set<int> pos[maxn];
int t[maxn * 4], lazy[maxn * 4];

void sieve(){
    nprime[0] = nprime[1] = 1;
    for(int i = 2; i * i < maxp; i++)
        if(!nprime[i])
            for(int j = i * i; j < maxp; j+=i)
                nprime[j] = 1; 
}

void push(int i){
    if(!lazy[i]) return;
    t[2 * i] += lazy[i];
    t[2 * i + 1] += lazy[i];
    lazy[2 * i] += lazy[i];
    lazy[2 * i + 1] += lazy[i];
    lazy[i] = 0;
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
}

int query(){
    return t[1];
}

void update(int cur, int val){
    if(nprime[cur] || pos[cur].empty())
        return;

    int l = *pos[cur].begin() + 1;
    int r = *pos[cur].rbegin() + 1;

    if(l <= n - 1) // 0 -> k - 1
        update(1, 1, n - 1, l, n - 1, val); 
    if(r > 1) // k -> n
        update(1, 1, n - 1, 1, min(r - 1, n - 1), val); 
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
    vi a(n), q(m, vi(2));
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++)
        cin>>q[i][0]>>q[i][1];
            
    memset(t, 0, sizeof t);
    memset(lazy, 0, sizeof lazy);

    sieve();
    for(int i = 0; i < n; i++)
        if(!nprime[a[i]])
            pos[a[i]].insert(i);

    for(int i = 2; i < maxn; i++)
        update(i, 1);

    vi res;
    for(const vi& v: q){
        int i = v[0], val = v[1];

        if(val != a[i]){
            if(!nprime[a[i]]){
                update(a[i], -1);
                pos[a[i]].erase(i);
                update(a[i], 1);
            }
            a[i] = val;

            if(!nprime[val]){
                update(val, -1);
                pos[val].insert(i);
                update(val, 1);
            }
        } 
        res.push_back(query());
    }
    for(int x : res) cout<<x<<" ";
    return 0;
}

// 5 2
// 2 1 3 1 2
// 1 2
// 3 3