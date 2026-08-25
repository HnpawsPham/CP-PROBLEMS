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
#define taskname "CHIENDAU"

struct Gun{
    int u, d, w;
    Gun(){};
    Gun(int u1, int d1, int w1) : u(u1), d(d1), w(w1) {};
};


int n, cost, m, q;
const int maxn = 5e4 + 5;
const ll oo = 1e16 + 5;
Gun a[maxn];

namespace sub1{
    void sol(){
        ll dp[n + 1];

        while(q--){
            int x, y, z;
            cin>>x>>y>>z;

            int en = y + z;
            vector<Gun> gun[en + 1];
            for(int i = 0; i < x; i++){
                if(a[i].u >= y && a[i].u <= en)
                    gun[a[i].u].push_back(a[i]);
            }

            for(int i = 0; i <= n; i++)
                dp[i] = oo;
            dp[y] = 0;
            
            for(int i = y; i < en; i++){
                if(dp[i] == oo) continue;
                dp[i + 1] = min(dp[i + 1], dp[i] + cost);

                for(const Gun& g : gun[i])
                    for(int j = 1; j <= g.d && i + j <= en; j++)
                        dp[i + j] = min(dp[i + j], dp[i] + g.w);
            }
            cout<<dp[en]<<el;
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

    cin>>n>>cost>>m>>q;
    for(int i = 0; i < m; i++)
        cin>>a[i].u>>a[i].d>>a[i].w;

    sub1::sol();
    return 0;
}