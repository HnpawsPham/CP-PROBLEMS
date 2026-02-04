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
#define plii pair<ll, pii>
//#define taskname ""

int n, m, k;
const int maxn = 1e5 + 5;
vector<pii> a[maxn];
const ll oo = 1e14 + 5;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    while(m--){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }

    priority_queue<plii, vector<plii>, greater<plii>> pq;
    vector<vll> dis(n + 1, vll(k + 1, oo));
    dis[1][k] = 0;
    pq.push({0, {1, k}});

    while(!pq.empty()){
        auto [w, cur] = pq.top();
        auto [u, cnt] = cur;
        pq.pop();

        if(w > dis[u][cnt]) continue;

        for(auto [w1, v] : a[u]){
            if(cnt > 0){
                if(dis[v][cnt - 1] > dis[u][cnt]){
                    dis[v][cnt - 1] = dis[u][cnt];
                    pq.push({dis[v][cnt - 1], {v, cnt - 1}});
                }
            }
   
            if(dis[v][cnt] > dis[u][cnt] + w1){
                dis[v][cnt] = dis[u][cnt] + w1;
                pq.push({dis[v][cnt], {v, cnt}});
            }
        }
    }
    cout<<*min_element(dis[n].begin(), dis[n].end());
    return 0;
}