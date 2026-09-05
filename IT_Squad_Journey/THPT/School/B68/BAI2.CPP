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
#define taskname "BAI2"

struct Point{
    int x, y, val;
    Point(){};
    Point(int x1, int y1, int val1): x(x1), y(y1), val(val1){}; 
};

int n;
const int maxn = 1e5 + 5;
const ll oo = 1e16 + 5;
Point a[maxn];

namespace sub2{
    const int maxsz = 1005;
    vector<pii> mp[maxsz];
    ll sum[maxsz];

    void sol(){
        for(const Point& p : a){
            int u = min(p.x, p.y);
            int v = max(p.x, p.y);

            mp[v].push_back({u, p.val});
        }

        memset(sum, 0, sizeof sum);

        ll res = -oo;
        for(int r = 0; r < maxsz; r++){
            for(const auto& [u, val] : mp[r]){
                for(int l = 0; l <= u; l++)
                    sum[l] += val;
            }

            for(int l = 0; l <= r; l++)
                res = max(res, sum[l] - r + l);
        }
        cout<<res;
    }
}

namespace sub3{
    const int maxsz = 1e5 + 5;
    ll t[maxsz * 4], lazy[maxsz * 4];
    vector<pii> mp[maxsz];

    void push(int i){
        if(!lazy[i]) return;
        lazy[2 * i] += lazy[i];
        lazy[2 * i + 1] += lazy[i];
        t[2 * i] += lazy[i];
        t[2 * i + 1] += lazy[i];
        lazy[i] = 0;
    }

    void build(int i, int l, int r){
        if(l == r){
            t[i] = l;
            return;
        }

        int mid = (l + r) / 2;
        build(2 * i, l, mid);
        build(2 * i + 1, mid + 1, r);
        t[i] = max(t[2 * i], t[2 * i + 1]);
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
    }

    ll query(int i, int st, int en, int l, int r){
        if(st > r || en < l) return -oo;
        if(st >= l && en <= r) return t[i];

        int mid = (st + en) / 2;
        push(i);
        return max(query(2 * i, st, mid, l, r), query(2 * i + 1, mid + 1, en, l, r));
    }

    void sol(){
        memset(t, 0, sizeof t);
        memset(lazy, 0, sizeof lazy);

        build(1, 1, maxsz);

        for(const Point& p : a){
            int u = min(p.x, p.y) + 1;
            int v = max(p.x, p.y) + 1;

            mp[v].push_back({u, p.val});
        }

        ll res = -oo;
        for(int r = 0; r < maxsz; r++){
            for(const auto& [u, val] : mp[r])
                update(1, 1, maxsz, 0, u, val);
    
            res = max(res, query(1, 1, maxsz, 0, r) - r);
        }
        cout<<res;
    }
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int maxx = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i].x>>a[i].y>>a[i].val;
        maxx = max(maxx, max(a[i].x, a[i].y));
    }

    if(n <= 1000 && maxx <= 1000)
        sub2::sol();
    else if(maxx <= 100000)
        sub3::sol();
    else cout<<0;
    return 0;
}