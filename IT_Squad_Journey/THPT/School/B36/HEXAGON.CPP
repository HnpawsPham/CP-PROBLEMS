#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define hex tuple<int, int, int>
#define pii pair<int, int>
#define vll vector<ll>
#define fi first
#define se second

int n;
const int maxn = 105;
const ll oo = 1e18 + 5; 

const int dy[3] = {1, -1 , 0},
          dx[3] = {0, -1, -1};

int VAL[maxn * 2][maxn * 2];
ll DP[maxn * 2][maxn * 2];

#define val(x, y) VAL[x + maxn][y + maxn]
#define dp(x, y) DP[x + maxn][y + maxn]

pii convert(int x, int y, int z){
    return {x, -y};
}

bool valid(int x, int y){
    return -n <= x && x <= n && -n <= y && y <= n;
}

int main(){
    // freopen("HEXAGON.INP", "r", stdin);
    // freopen("HEXAGON.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int m = 1 + 3 * n * (n + 1);
    for(int i = 0; i < m; i++){
        int q, r, s, w;
        cin>>q>>r>>s>>w;
        auto [x, y] = convert(q, r, s);
        val(x, y) = w;
    }

    int q, r, s;
    cin>>q>>r>>s;
    auto [tx, ty] = convert(q, r, s);
    auto [sx, sy] = convert(0, -n, n);

    memset(DP, -1, sizeof DP);
    dp(sx, sy) = val(sx, sy);

    for(int j = n; j >= -n; j--)
        for(int i = -n; i <= n; i++){
            if(dp(i, j) == -oo) continue;
            
            for(int x = 0; x < 3; x++){
                int i1 = i + dy[x];
                int j1 = j + dx[x];

                if(valid(i1, j1)) 
                    dp(i1, j1) = max(dp(i1, j1), dp(i, j) + val(i1, j1));
            }
        }
    cout<<dp(tx, ty);

    // DIJKSTRA MAX
    // map<hex, int> a;

    // for(int i = 0; i < m; i++){
    //     int x, y, z, w;
    //     cin>>x>>y>>z>>w;
    //     a[{x, y, z}] = w;
    // }

    // int x, y, z;
    // cin>>x>>y>>z;
    // hex target = {x, y, z};

    // int dx[3] = {1, -1, 0},
    //     dy[3] = {0, 1, 1},
    //     dz[3] = {-1, 0, -1};

    // priority_queue<pair<ll, hex>> q;
    // map<hex, ll> dp;
    // hex st = {0, -n, n};

    // dp[st] = a[st];
    // q.push({a[st], st});

    // while(!q.empty()){
    //     auto [w, u] = q.top();
    //     auto [x, y, z] = u;
    //     q.pop();

    //     if(w < dp[u]) continue;

    //     for(int i = 0; i < 3; i++){
    //         int x1 = x + dx[i];
    //         int y1 = y + dy[i];
    //         int z1 = z + dz[i];
    //         hex v = {x1, y1, z1};

    //         if(!a.count(v)) continue;

    //         ll cost = dp[u] + a[v];
    //         if(!dp.count(v) || cost > dp[v]){
    //             dp[v] = cost;
    //             q.push({dp[v], v});
    //         }
    //     }
    // }  
    // cout<<(dp.count(target) ? dp[target] : 0);
    return 0;
}

// 1
// 0 0 0 5
// 0 -1 1 5
// 0 1 -1 5
// -1 0 1 5
// 1 0 -1 5
// -1 1 0 5
// 1 -1 0 5
// 0 1 -1