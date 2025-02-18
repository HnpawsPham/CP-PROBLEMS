#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second

int n, m, k, q;
const int maxn = 3 * (int)1e5 + 5;
const int maxd = (int)1e4 + 5;

queue<pii> src;
vector<pii> a[maxn];
vector<vector<int>> dis(maxd, vector<int>(maxn, INT_MAX));
bool check[maxn];
bool special[maxn];

void bfs(){
    for(int d = 1; d <= maxd; d++){
        queue<int> q;
        for(int i = 1; i<= n;i++){
            dis[d][i] = 0;
            if(special[i]) q.push(i);
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(pii x : a[u]){
                int v = x.fi;
                int c = x.se;

                if(!check[v] && c % d == 0){
                    src.push({v, d});
                    dis[d][v] = dis[d][u] + 1;
                    check[v] = 1;
                }
            }
        }
    }
    return;
}

int main(){
    freopen(".\\txt\\HOICHO.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k>>q;
    for(int i = 1; i<= n; i++){
        special[i] = 1;
        check[i] = 1;
    }

    while(k--){
        int s; cin>>s;
        special[s] = 0;
        check[s] = 0;
    }

    while(m--){
        int u, v, c;
        cin>>u>>v>>c;

        a[u].push_back({v, c});
        a[v].push_back({u, c});
    }



    while(q--){
        int x, d;
        cin>>x>>d;

        src.push({x, d});
    }
    bfs();


    return 0;
}