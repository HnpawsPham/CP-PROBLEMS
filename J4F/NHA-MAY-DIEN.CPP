#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define fi first
#define se second
//#define taskname ""

int n, m, k;
const int maxn = 2e5 + 5;
vi a[maxn];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "left", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    while(m--){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    priority_queue<pli> pq;
    vll best(n + 1, -1);

    while(k--){
        int p, r;
        cin>>p>>r;
        pq.push({r, p});
        best[p] = r;
    }

    while(!pq.empty()){
        auto [left, u] = pq.top();
        pq.pop();

        if(left < best[u]) continue;

        for(int v : a[u])
            if(left - 1 > best[v]){
                best[v] = left - 1;
                pq.push({best[v], v});
            }
    }

    for(int i = 1; i <= n; i++)
        if(best[i] >= 0) cout<<1;
        else cout<<0;
    return 0;
}