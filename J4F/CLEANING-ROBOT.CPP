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
//#define taskname ""

struct block{
    int i, j, mask;
    block(){};
    block(int i1, int j1, int mask1): i(i1), j(j1), mask(mask1){};
};

int n, m, k, stx, sty;
const int maxn = 25;
const int oo = 40005;
char a[maxn][maxn];
int dis[maxn][maxn], d[maxn][maxn];

int dy[4] = {-1, 1, 0, 0},
    dx[4] = {0, 0, -1, 1};

void calc_dis(int id, pii u, const vector<pii>& dirt){
    queue<pii> q;
    for(int i= 0; i < n; i++)
        for(int j = 0; j < m; j++)
            d[i][j] = oo;
    
    q.push({u.fi, u.se});
    d[u.fi][u.se] = 0;

    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();

        for(int x = 0; x < 4; x++){
            int i1 = i + dy[x];
            int j1 = j + dx[x];

            if(i1 < 0 || j1 < 0 || i1 == n || j1 == m || a[i1][j1] == 'x')
                continue;

            if(d[i1][j1] <= d[i][j] + 1) 
                continue;

            d[i1][j1] = d[i][j] + 1;
            q.push({i1, j1});
        }
    }

    for(int i = 0; i < k; i++)
        dis[id][i + 1] = d[dirt[i].fi][dirt[i].se];
}

int dp[(1 << 10)][maxn];

int dfs(int mask, int u){
    if(mask == (1 << k) - 1)   
        return 0;
    
    if(dp[mask][u] != -1)
        return dp[mask][u];

    int res = oo;
    for(int i = 0; i < k; i++){
        if(!(mask & (1 << i)))
            if(dis[u + 1][i + 1] != oo)
                res = min(res, dis[u + 1][i + 1] + dfs(mask | (1 << i), i));
    }
    return dp[mask][u] = res;
}

int sol(){
    vector<pii> dirt;
    for(int i= 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin>>a[i][j];
            if(a[i][j] == 'o'){
                stx = i;
                sty = j;
            }
            else if(a[i][j] == '*')
                dirt.push_back({i, j});
        }

    k = dirt.size();

    calc_dis(0, {stx, sty}, dirt); // from start point
    for(int i = 0; i < k; i++)
        calc_dis(i + 1, dirt[i], dirt);

    memset(dp, -1, sizeof dp);
    int res = oo;
    for(int i = 0; i < k; i++){
        if(dis[0][i + 1] == oo) continue;
        res = min(res, dis[0][i + 1] + dfs(1 << i, i)); 
    }
    return (res == oo ? -1 : res);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(1){
        cin>>m>>n;
        if(n == 0 && m == 0) break;
        cout<<sol()<<el;
    }

    return 0;
}