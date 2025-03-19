#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second

int n, m, s, t, psz;
const int maxn = 1e5 + 5;
const int maxp = 1e6;
vector<vector<pii>> a(maxn);
vector<int> prime;
bool nprime[maxp];

void sieve(){
    nprime[0] = nprime[1] = 1;
    for(int i = 2; i * i < maxp; i++){
        if(!nprime[i])
            for(int j = i * i; j < maxp; j += i) 
                nprime[j] = 1;
    }
    for(int i = 2; i < maxp; i++) 
        if(!nprime[i]) prime.push_back(i);
    psz = prime.size();
    return;
}

void dijkstra(int src){
    vector<int> dis(n + 1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[src] = 0;
    pq.push({dis[src], src});

    while(!pq.empty()){
        pii cur = pq.top();
        pq.pop();

        int u = cur.se;
        int w = cur.fi;
        if(w > dis[u]) continue;

        for(pii x : a[u]){
            int v = x.se;
            int w1 = x.fi;

            if(dis[v] > dis[u] + w1){
                dis[v] = dis[u] + w1;
                pq.push({dis[v], v});
            }
        }
    }
    cout<<dis[t];
    return;
}

int main(){
    freopen("DDNT.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>s>>t;
    sieve();

    while(m--){
        int u, v, w; 
        cin>>u>>v>>w;
        int pos = lower_bound(prime.begin(), prime.end(), w) - prime.begin();
        if(pos < psz) w = prime[pos] - w;

        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }
    dijkstra(s);

    return 0;
}