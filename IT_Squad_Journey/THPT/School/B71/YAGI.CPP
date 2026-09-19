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
#define taskname "YAGI"

int n, q;
const int maxn = 2e5 + 5;
const int LOG = 18;
const ll oo = 1e17 + 5;
ll total = 0;
vector<pii> a[maxn], ra[maxn];
int test[maxn];

namespace sub1{
    void sol(){
        while(q--){
            int t;
            cin>>t;
            if(test[t] != -1){
                cout<<test[t]<<el;
                continue;
            }

            ll res = oo;
            for(int i = 0; i < (1 << n); i++){
                ll sum = 0;
                if(__builtin_popcount(i) != t) continue;

                vi chosen;
                for(int j = 1; j <= n; j++)
                    if(!(i & (1 << (j - 1))))
                        chosen.push_back(j);

                for(int u : chosen)
                    for(int v = 1; v <= n; v++)
                        sum += 
                res = min(res, sum);
            }
            cout<<res<<el;
        }
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

    cin>>n>>q;
    for(int i = 1; i < n; i++){
        int u, v, x, y;
        cin>>u>>v>>x>>y;
        a[u].push_back({x, v});
        ra[v].push_back({y, u});
        total += x + y;
    }

    memset(test, -1, sizeof test);
    return 0;
}