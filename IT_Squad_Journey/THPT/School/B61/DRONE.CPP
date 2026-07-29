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
#define taskname "DRONE"

struct line{
    int u, v, w;
    line() {};
    line(int u1, int v1, int w1): u(u1), v(v1), w(w1) {};
};

int n, m;
const int maxn = 1e5 + 5;
const ll oo = 1e16 + 5;
vector<line> a;

namespace sub1{
    void sol(){     
        while(m--){
            int l, r;
            cin>>l>>r;

            ll res = oo;
            for(const line& x : a)
                res = min(res, 1LL * abs(x.u - l) + 1LL * abs(x.v - r) + 1LL * x.w);
            cout<<res<<el;
        }
    }
}

namespace sub2{
    vector<pii> q;
    bool check(){
        int minl = 1e9 + 5, minr = 1e9 + 5;

        while(m--){
            int l, r;
            cin>>l>>r;
            q.push_back({l, r});

            minl = min(minl, l);
            minr = min(minr, r);
        }

        for(const line& x : a)
            if(minl < x.u || minr < x.v) return 0;
        return 1;
    }

    void sol(){
        ll maxx = -oo;
        for(const line& x : a)
            maxx = max(maxx, 1LL * x.u + 1LL * x.v - 1LL * x.w);

        for(const auto& [l, r] : q)
            cout<<min(1LL * abs(r - l), 1LL * l + 1LL * r - maxx)<<el;
    }
}

namespace sub3{
    void sol(){
        sub1::sol();
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

    cin>>n>>m;
    for(int i = 0; i < n; i++){
        int u, v, w;
        cin>>u>>v>>w;
        a.push_back({u, v, w});
    }

    sub1::sol();

    // if(sub2::check())
    //     sub2::sol();
    // else sub3::sol();
    return 0;
}

// 5 3
// 5 10 2
// 12 20 1
// 18 7 3
// 15 25 3
// 22 12 4
// 6 20
// 12 30
// 15 22