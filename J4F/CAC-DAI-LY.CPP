#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define piii pair<pii, int>
#define fi first
#define se second
//#define taskname ""

int n, m, s, t;
const int maxn = 255;
vi a[maxn];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>s>>t;
    while(m--){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
    }

    const int oo = 1e9 + 5;
    queue<piii> q;
    q.push({{s, t}, 0});
    vector<vector<vi>> dis(n + 1, vector<vi>(n + 1, vi(2, oo)));
    dis[s][t][0] = 0;

    int res = oo;
    while(!q.empty()){
        auto [pos, waiting] = q.front();
        q.pop();

        if(waiting == 0 && pos.fi == pos.se){
            res = dis[pos.fi][pos.se][0];
            break;
        }

        if(waiting == 0){
            for(int u : a[pos.se])
                if(dis[pos.fi][u][1] > dis[pos.fi][pos.se][0]){
                    dis[pos.fi][u][1] = dis[pos.fi][pos.se][0];
                    q.push({{pos.fi, u}, 1});
                }
        }
        else{
            for(int v : a[pos.fi])
                if(dis[v][pos.se][0] > dis[pos.fi][pos.se][1] + 1){
                    dis[v][pos.se][0] = dis[pos.fi][pos.se][1] + 1;
                    q.push({{v, pos.se}, 0});
                }
        }
    }

    cout<<(res == oo ? -1 : res);
    return 0;
}