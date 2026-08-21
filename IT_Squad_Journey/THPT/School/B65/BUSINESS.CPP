#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
#define taskname "BUSINESS"

int n, m, q;
const int maxn = 1e5 + 5;
const ll oo = 1e18;
int a[maxn];
ll b[maxn];

ll inc(ll old, ll d){
    if(oo - old < d)
        return oo;
    return old + d;
}

ll dec(ll old, ll d){
    if(old < -oo + d)
        return -oo;
    return old - d;
}

ll mul(ll old, ll d){
    if(d == 0) return 0;
    if(old > oo / d)
        return oo;
    return old * d;
}

struct BIT{
    ll t[maxn];

    BIT(){
        memset(t, 0, sizeof t);
    }

    void add(int i, ll val){
        while(i < maxn){
            t[i] = inc(t[i], val);
            i += (i & -i);
        }
    }

    ll query(int i){
        ll res = 0;
        while(i > 0){
            res = inc(res, t[i]);
            i -= (i & -i);
        }
        return res;
    }
};

namespace sub1{
    void sol(){
        int res[m + 1];
        memset(res, -1, sizeof res);

        ll p[m + 5];
        memset(p, 0, sizeof p);

        for(int t = 1; t <= q; t++){
            int l, r;
            ll k, d;
            cin>>l>>r>>k>>d;

            for(int i = l; i <= r; i++)
                p[a[i]] = inc(p[a[i]], inc(k, mul((i - l), d)));

            for(int i = 1; i <= m; i++)
                if(res[i] == -1 && p[i] >= b[i])
                    res[i] = t;
        }

        for(int i = 1; i <= m; i++)
            cout<<res[i]<<" ";
    }
}

namespace sub3{
    void sol(){
        ll sum = 0;

        for(int i = 0; i < q; i++){
            int l, r;
            ll k, d;
            cin>>l>>r>>k>>d;
            // k - ld + xd
            int sz = r - l + 1;
            sum = inc(sum, mul(sz, dec(k, mul(l, d))));
            sum = inc(sum, d * (mul((l + r), sz) / 2));

            if(sum >= b[1]){
                cout<<i + 1;
                return;
            }
        }
        cout<<-1;
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

    cin>>n>>m>>q;
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= m; i++) cin>>b[i];

    if(m == 1) sub3::sol();
    else sub1::sol();
    return 0;
}

// 5 3 6 
// 1 1 2 2 3 
// 120 50 100 
// 1 3 20 10 
// 3 5 35 15 
// 1 5 50 10 
// 2 3 10 10 
// 2 4 20 10 
// 1 5 50 5