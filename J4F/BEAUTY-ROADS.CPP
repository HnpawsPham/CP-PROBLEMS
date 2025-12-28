#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<ll, ll>
#define piii pair<pii, int>
#define fi first
#define se second
//#define taskname ""

int n, m;
const int maxn = 2e5 + 5;
const ll oo = 1e16 + 5;
vector<piii> a[maxn];

struct comp{
    bool operator()(const piii& a, const piii& b) const {
        if(a.fi.fi != b.fi.fi) return a.fi.fi > b.fi.fi;
        return a.fi.se < b.fi.se;
    }
};

void dijkstra(){
    priority_queue<piii, vector<piii>, comp> pq;
    vector<pii> state(n + 1, {oo, 0});
    state[1] = {0, 0};
    pq.push({state[1], 1});

    while(!pq.empty()){
        auto [cur, u] = pq.top();
        auto [w, val] = cur;
        pq.pop();

        if (w > state[u].fi || (w == state[u].fi && val < state[u].se))
            continue;

        for(auto [tmp, v] : a[u]){
            auto [w1, val1] = tmp;
            if((state[v].fi > state[u].fi + w1)
            || (state[v].fi == state[u].fi + w1 && state[v].se < state[u].se + val1)){

                state[v].fi = state[u].fi + w1;
                state[v].se = state[u].se + val1;
                pq.push({state[v], v});
            }
        }
    }
    
    if(state[n].fi != oo)
        cout<<state[n].fi<<" "<<state[n].se;
    else cout<<-1;
    return;
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
    while(m--){
        int u, v;
        ll w, val;
        cin>>u>>v>>w>>val;
        a[u].push_back({{w, val}, v});
        a[v].push_back({{w, val}, u});
    }
    dijkstra();
    return 0;
}