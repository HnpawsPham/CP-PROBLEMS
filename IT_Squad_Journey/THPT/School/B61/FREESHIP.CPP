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
#define taskname "FREESHIP"

struct order{
    int st, pos, t;
    order(){};
    order(int st1, int pos1, int t1) : st(st1), pos(pos1), t(t1) {};
};

int n, m, k;
const int maxn = 1005;
const ll oo = 1e16 + 5;

vector<pii> a[maxn];
ll dis[maxn][maxn];
vector<order> q;

void dijkstra(int st){
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dis[st][st] = 0;
    pq.push({0, st});

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(w > dis[st][u]) continue;

        for(auto [w1, v] : a[u]){
            if(dis[st][v] > dis[st][u] + w1){
                dis[st][v] = dis[st][u] + w1;
                pq.push({dis[st][v], v});
            }
        }
    }
}

ll dp[maxn];
bool check(ll t){
    for(int i = 1; i <= k; i++)
        dp[i] = oo;
    dp[0] = 0;

    for(int i = 1; i <= k; i++)
        for(int j = 0; j < i; j++){
            // leave shop time + den noi nhan
            ll wait = max(dp[j], 1LL * q[i - 1].t) + dis[1][q[j].pos];
            if(wait - q[j].st > t) continue; 

            bool ok = 1;
            for(int x = j + 1; x < i; x++){
                wait += dis[q[x - 1].pos][q[x].pos];
                if(wait - q[x].st > t){
                    ok = 0;
                    break;
                }
            }
            if(ok) dp[i] = min(dp[i], wait + dis[q[i - 1].pos][1]);
        }
    return dp[k] != oo;
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
        int u, v, w;
        cin>>u>>v>>w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dis[i][j] = oo;

    for(int i = 1; i <= n; i++)
        dijkstra(i);

    cin>>k;
    for(int i = 0; i < k; i++){
        int s, u, t;
        cin>>s>>u>>t;
        q.push_back({s, u, t});
    }

    ll l = 0, r = oo, mid, res = oo;
    while(l <= r){
        mid = l + (r - l) / 2;
        if(check(mid)){
            r = mid - 1;
            res = mid;
        }
        else l = mid + 1;
    }
    cout<<res;
    return 0;
}