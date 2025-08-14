#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int, int>
#define fi first
#define se second

int n, m;
vector<vi> a;

int dy[4] = {-1, 0, 0, 1},
    dx[4] = {0, -1, 1, 0};

bool bfs(int lim, vector<vi>& obs){
    a.assign(n + 1, vi(m + 1, 0));

    for(int i = 0; i <= lim; i++)
        a[obs[i][0]][obs[i][1]] = 1;

    queue<pii> q;
    vector<vb> check(n + 1, vb(m + 1, 0));

    for(int j = 1; j <= m; j++){
        if(a[1][j]) continue;
        q.push({1, j});
        check[1][j] = 1;
    }

    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();

        if(i == n) return 1;

        for(int x = 0; x < 4; x++){
            int i1 = i + dy[x];
            int j1 = j + dx[x];

            if(i1 < 1 || j1 < 1 || i1 > n || j1 > m || a[i1][j1] || check[i1][j1]) continue;
            q.push({i1, j1});
            check[i1][j1] = 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vector<vi> obs(n * m);
    for(int i = 0; i < n * m; i++){
        int u, v;
        cin>>u>>v;
        obs[i] = {u, v};
    }

    int l = 0, r = n * m - 1;
    while(l <= r){
        int mid = (l + r) / 2;

        if(bfs(mid, obs)) l = mid + 1;
        else r = mid - 1;
    }
    cout<<l;
    return 0;
}

// 2 2 
// 1 1
// 2 1
// 1 2
// 2 2