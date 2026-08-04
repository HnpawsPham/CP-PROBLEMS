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
#define taskname "maxval"

int n;
const ll oo = 1e11 + 5;
const int maxn = 5e4 + 5;
int a[maxn];

namespace sub1{
    int t[maxn * 4];

    void build(int i, int l, int r){
        if(l == r){
            t[i] = a[l];
            return;
        }

        int mid = (l + r) / 2;
        build(2 * i, l, mid);
        build(2 * i + 1, mid + 1, r);
        t[i] = max(t[2 * i], t[2 * i + 1]);
    }

    int getmax(int i, int st, int en, int l, int r){
        if(st > r || en < l) return -1e6 - 5;
        if(st >= l && en <= r) return t[i];

        int mid = (st + en) / 2;
        return max(getmax(2 * i, st, mid, l, r), getmax(2 * i + 1, mid + 1, en, l, r));
    }

    void sol(){
        ll p[n + 5];
        memset(p, 0, sizeof p);
        p[0] = 0;
        for(int i = 1; i <= n ;i++)
            p[i] = p[i - 1] + a[i];

        build(1, 1, n);

        ll res = -oo;
        for(int i = 1; i <= n; i++){
            int g = 0;
            for(int j = i; j <= n; j++){
                g = __gcd(abs(a[j]), g);
                res = max(res, 1LL * g * (p[j] - p[i - 1] - getmax(1, 1, n, i, j)));
            }
        }
        cout<<res;
    }
}

namespace sub2{
    int t[maxn * 4];

    void build(int i, int l, int r){
        if(l == r){
            t[i] = a[l];
            return;
        }

        int mid = (l + r) / 2;
        build(2 * i, l, mid);
        build(2 * i + 1, mid + 1, r);
        t[i] = max(t[2 * i], t[2 * i + 1]);
    }

    int getmax(int i, int st, int en, int l, int r){
        if(st > r || en < l) return -1e6 - 5;
        if(st >= l && en <= r) return t[i];

        int mid = (st + en) / 2;
        return max(getmax(2 * i, st, mid, l, r), getmax(2 * i + 1, mid + 1, en, l, r));
    }

    void sol(){
        ll p[n + 1];
        p[0] = 0;
        for(int i = 1; i <=n ;i++)
            p[i] = p[i - 1] + a[i];

        build(1, 1, n);

        vector<pii> mp;
        ll res = 0;

        for(int i = 1; i <= n; i++){
            vector<pii> tmp;
            tmp.push_back({abs(a[i]), i});

            for(int j = 0; j < mp.size(); j++){
                int g = __gcd(abs(a[i]), mp[j].fi);

                if(tmp.back().fi == g)
                    tmp.back().se = min(tmp.back().se, mp[j].se);
                else tmp.push_back({g, mp[j].se});
            }
            mp = tmp;

            int m = mp.size();
            for(int j = 0; j < m; j++){
                int l = mp[j].se;
                int r = (j + 1 < m ? mp[j + 1].se - 1 : i);
                
                for(int x = l; x <= r; x++)
                    res = max(res, 1LL * mp[j].fi * (p[i] - p[x - 1] - getmax(1, 1, n, x, l)));
            }
        }
        cout<<res;
    }
}

int main(){
    #ifdef taskname
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    memset(a, 0, sizeof a);
    for(int i = 1; i <= n; i++) cin>>a[i];

    if(n <= 3000)
        sub1::sol();
    else sub2::sol();
    return 0;
}