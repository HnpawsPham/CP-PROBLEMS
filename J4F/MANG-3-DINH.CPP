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

int n, m;
const int maxn = 505;
const int oo = 1e8 + 5;
int id[maxn][maxn], w[maxn][maxn], mid[maxn][maxn];
bool check[maxn][maxn] = {0};

void trace(int u, int v){
    if(u == v) return;

    if(!mid[u][v]){
        check[u][v] = check[v][u] = 1;
        return;
    }

    trace(u, mid[u][v]);
    trace(v, mid[u][v]);
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

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++){
            if(i == j) w[i][j] = 0;
            else w[i][j] = w[j][i] = oo;
            mid[i][j] = mid[j][i] = 0;
        }

    for(int i = 1; i <= m; i++){
        int u, v, c;
        cin>>u>>v>>c;
        if(c < w[u][v]){
            id[u][v] = id[v][u] = i;
            w[u][v] = w[v][u] = c;
        }
    }

    // floyd
    int dis[n + 1][n + 1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dis[i][j] = w[i][j];

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(dis[i][j] > dis[i][k] + dis[k][j]){
                dis[i][j] = dis[i][k] + dis[k][j];
                mid[i][j] = k;
            }

    // try x
    int minn = oo, x;
    for(int i = 1; i <= n; i++)
        if(dis[1][i] + dis[2][i] + dis[3][i] < minn){
            minn = dis[1][i] + dis[2][i] + dis[3][i];
            x = i;
        }

    trace(1, x);
    trace(2, x);
    trace(3, x);

    vi res;
    int sum = 0;
    for(int i = 1; i <= n; i++) 
        for(int j = i + 1; j <= n; j++)
            if(check[i][j]){
                sum += dis[i][j];
                res.push_back(id[i][j]);
            }

    cout<<sum<<el<<res.size()<<el;
    for(int x : res) cout<<x<<" ";
    return 0;
}