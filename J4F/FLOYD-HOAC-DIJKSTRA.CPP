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

int n, m, q;
const int oo = 2e6 + 5;
// vector<pii> a[n];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>q;
    vector<vi> len(n + 1, vi(n + 1, oo)),
               next(n + 1, vi(n + 1, -1));

    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        // a[u].push_back({w, v});
        // a[v].push_back({w, u});
        len[u][v] = len[v][u] = w;
        next[u][v] = v;
        next[v][u] = u;
    }

    for(int i = 1; i <= n; i++){
        len[i][i] = 0;
        next[i][i] = i;
    }

    for(int k = 1; k <= n; k++)
        for(int u = 1; u <= n; u++)
            for(int v = 1; v <= n; v++){
                if(len[u][k] + len[k][v] < len[u][v]){
                    len[u][v] = len[u][k] + len[k][v];
                    next[u][v] = next[u][k];
                }
            }

    while(q--){
        int opt, u, v;
        cin>>opt>>u>>v;
        if(opt == 0) cout<<len[u][v]<<el;
        else{
            vi res;
            bool ok = 1;
            while(u != v){
                res.push_back(u);
                u = next[u][v];

                if(u == -1) {
                    cout<<-1<<el;
                    ok = 0;
                    break;
                }
            } 
            res.push_back(v);
        
            if(!ok) continue;
            cout<<res.size();
            for(const int& x : res) cout<<" "<<x;
            cout<<el;
        }
    }
    return 0;
}