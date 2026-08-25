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

int dy[4] = {-1, 0, 0, 1},
    dx[4] = {0, -1, 1, 0};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    int a[n][m];
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) cin>>a[i][j];

    queue<pii> q;
    int dis[n][m];
    const int oo = n * m * 2;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
                dis[i][j] = oo;
    
    q.push({0, 0});
    dis[0][0] = 0;


    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();

        for(int x = 0; x < 4; x++){
            int i1 = i + dy[x];
            int j1 = j + dx[x];

            if(i1 < 0 || j1 < 0 || i1 == n || j1 == m)
                continue;

            if(dis[i1][j1] > dis[i][j] + a[i1][j1]){
                dis[i1][j1] = dis[i][j] + a[i1][j1];
                q.push({i1, j1});
            }
        }
    }
    cout<<dis[n - 1][m - 1];
    return 0;
}

// 3 3
// 0 1 1
// 1 1 0
// 1 1 0