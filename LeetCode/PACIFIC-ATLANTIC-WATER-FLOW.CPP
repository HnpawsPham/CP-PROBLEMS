#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define vb vector<bool>
#define fi first
#define se second

int n, m;
int dy[4] = {-1, 1, 0, 0},
    dx[4] = {0, 0, -1, 1};

vector<vb> bfs(const vector<vi>& a, int posx, int posy){
    queue<pii> q;
    vector<vb> check(n, vb(m, 0));

    for(int i = 0; i < m; i++) {
        q.push({posx, i});
        check[posx][i] = 1;
    }
    for(int i = 0; i < n; i++){
        q.push({i, posy});
        check[i][posy] = 1;
    }

    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();

        for(int x = 0; x < 4; x++){
            int i1 = i + dy[x];
            int j1 = j + dx[x];

            if(i1 < 0 || j1 < 0 || i1 == n || j1 == m || check[i1][j1] || a[i1][j1] < a[i][j]) continue;
            check[i1][j1] = 1;
            q.push({i1, j1});
        }
    }
    return check;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vector<vi> a(n, vi(m));
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) cin>>a[i][j];

    vector<vb> pacific = bfs(a, 0, 0), atlantic = bfs(a, n - 1, m - 1);

    vector<vi> res;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(pacific[i][j] && atlantic[i][j])
                res.push_back({i, j});

    for(auto v : res) 
        cout<<v[0]<<" "<<v[1]<<el;
    return 0;
}

// 5 5
// 1 2 2 3 5
// 3 2 3 4 4
// 2 4 5 3 1
// 6 7 1 4 5
// 5 1 1 2 4
