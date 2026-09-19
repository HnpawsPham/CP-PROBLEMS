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
#define taskname "RELIEP"

int n, q;
const int oo = 1e6 + 5;
const int maxn = 2e5 + 5;
bool mark[maxn];
vector<pii> que;
vi a[maxn];

namespace sub1{
    const int maxsz = 1005;
    int d[maxsz][maxsz], dis[maxsz];

    void bfs(int u){
        queue<int> q;
        for(int i = 1; i <= n; i++)
            dis[i] = oo;
        
        q.push(u);
        dis[u] = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v: a[u]){
                if(dis[v] > dis[u] + 1){
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }

        for(int i = 1; i <= n; i++)
            d[u][i] = dis[i];
    }

    void sol(){
        for(int i = 1; i<= n; i++)
            bfs(i);

        for(const auto& [opt, u]: que){
            if(opt == 1)
                mark[u] = 1;
            else{
                if(mark[u]) cout<<0<<el;
                else{
                    int minn = oo;
                    for(int i = 1; i <= n; i++)
                        if(mark[i]) minn = min(minn, d[i][u]);
                    cout<<minn<<el;
                }
            }
        }
    }
}

namespace sub2{
    bool has2 = 0, checksub = 1;
    int dis[maxn];

    void sol(){
        queue<int> q;
        for(int i = 1; i <= n; i++) 
            dis[i] = oo;

        for(const auto& [opt, u] : que){
            if(opt == 2) break;
            mark[u] = 1;
            dis[u] = 0;
            q.push(u);
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v : a[u]){
                if(dis[v] > dis[u] + 1){
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
    
        for(const auto& [opt, u] : que){
            if(opt == 1) continue;
            cout<<dis[u]<<el;        
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
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    mark[1] = 1;

    que.resize(q);
    for(int i = 0; i < q; i++){
        cin>>que[i].fi>>que[i].se;
        if(que[i].fi == 2) sub2::has2 = 1;
        if(que[i].fi == 1 && sub2::has2) sub2::checksub = 0;
    }

    if(sub2::checksub)
        sub2::sol();
    else sub1::sol();
    return 0;
}