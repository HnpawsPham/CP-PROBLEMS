#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m;
const int maxn = 1e6 + 5;
string a[maxn];
int dy[4] = {1, 0},
    dx[4] = {0, 1};

bool valid(int i, int j){
    if(i >= 0 && i < n && j >= 0 && j < m && a[i][j] == '.') return 1;
    return 0;
}

vector<vi> bfs(int x, int y, int dir){
    vector<vi> dis(n, vi(m, -1));
    queue<pii> q;
    q.push({x, y});
    dis[x][y] = 0;

    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();

        for(int x = 0; x < 2; x++){
            int i1 = i + dy[x] * dir;
            int j1 = j + dx[x] * dir;

            if(!valid(i1, j1)) continue;
            if(dis[i1][j1] != -1) continue;

            q.push({i1, j1});
            dis[i1][j1] = dis[i][j] + 1;
        }
    }
    return dis;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>a[i];
  
    vector<vi> dis1 = bfs(0, 0, 1), disn = bfs(n - 1, m - 1, -1);
    if(dis1[n - 1][m - 1] == -1) return cout<<0, 0;

    int path = n - 1 + m - 1;
    int cnt[path + 1] = {0};

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(dis1[i][j] != -1 && disn[i][j] != -1
            && dis1[i][j] + disn[i][j] == path)
                cnt[dis1[i][j]]++;

    for(int i = 1; i < path; i++)
        if(cnt[i] == 1) return cout<<1, 0;

    cout<<2;
    return 0;
}