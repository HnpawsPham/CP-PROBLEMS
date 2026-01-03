#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<ll, int>
#define fi first
#define se second
//#define taskname ""

int n, l, r, c, st, en;
const ll oo = 1e15 + 5;
const int maxn = 1e5 + 5;
vi g[maxn];
int a[maxn];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>l>>r>>c;
    cin>>st>>en;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        g[a[i]].push_back(i);
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vll dis(n + 1, oo);
    dis[st] = 0;
    pq.push({0, st});

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(w > dis[u]) continue;
        if(u == en) break;

        if(u < n && dis[u + 1] > dis[u] + r){
            dis[u + 1] = dis[u] + r;
            pq.push({dis[u + 1], u + 1});
        }
        if(u > 1 && dis[u - 1] > dis[u] + l){
            dis[u - 1] = dis[u] + l;
            pq.push({dis[u - 1], u - 1});
        }
        for(int v : g[a[u]]){
            if(v == u) continue;
            if(dis[v] > dis[u] + c){
                dis[v] = dis[u] + c;
                pq.push({dis[v], v});
            }
        }
    }
    cout<<dis[en];
    return 0;
}