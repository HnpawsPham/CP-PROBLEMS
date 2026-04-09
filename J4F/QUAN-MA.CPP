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
#define taskname "QUANMA"

int n, m;
const int maxn = 1005;
int dy[8] = {-2, -2, -1, - 1, 1, 1, 2, 2},
    dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int stx, sty, enx, eny;
    cin>>stx>>sty>>enx>>eny;

    queue<pii> q;
    q.push({stx, sty});
    int dis[n + 1][m + 1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dis[i][j] = maxn * maxn * 2;

    dis[stx][sty] = 0;

    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();

        if(i == enx && j == eny) break;

        for(int x = 0; x < 8; x++){
            int i1 = i + dy[x];
            int j1 = j + dx[x];
            if(i1 <= 0 || j1 <= 0 || i1 > n || j1 > m) continue;
            if(dis[i1][j1] > dis[i][j] + 1){
                q.push({i1, j1});
                dis[i1][j1] = dis[i][j] + 1;
            }
        }
    }  
    cout<<dis[enx][eny];
    return 0;
}