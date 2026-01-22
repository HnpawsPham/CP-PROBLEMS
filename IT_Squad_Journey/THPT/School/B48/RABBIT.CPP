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
#define taskname "RABBIT"

int n, x, y;
int dy[3] = {1, 0, 0},
    dx[3] = {0, -1, 1};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>x>>y;
    int a[n + 1][n + 1];
    memset(a, 0, sizeof a);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin>>a[i][j];

    queue<pii> q;
    int dis[n + 1][n + 1];
    memset(dis, 0, sizeof dis);
    q.push({1, 1});
    dis[1][1] = 1;
    
    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();

        if(i == x && j == y) break;

        for(int x = 0; x < 3; x++){
            int i1 = i + dy[x];
            int j1 = j + dx[x];

            if(i1 < 1 || i1 > n || j1 < 1 || j1 > n || a[i1][j1]) continue;
            q.push({i1, j1});
            a[i1][j1] = 1;
            dis[i1][j1] = dis[i][j] + 1;
        }
    }
    cout<<dis[x][y];
    return 0;
}