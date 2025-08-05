#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<vi> a(n, vi(n));
    for(int i = 0; i < n; i++)  
        for(int j = 0; j < n; j++) cin >>a[i][j];

    if(a[0][0] == 1) return cout<<-1, 0;

    queue<pii> q;
    q.push({0, 0});
    vector<vi> dis(n, vi(n, -1));
    dis[0][0] = 1;

    int dy[8] = {-1, 1, -1, 1, 1, -1, 0, 0},
        dx[8] = {0, 0, -1, 1, -1, 1, -1, 1};

    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();
        a[i][j] = 1;

        for(int x = 0; x < 8; x++){
            int i1 = i + dy[x];
            int j1 = j + dx[x];

            if(i1 < 0 || j1 < 0 || i1 == n || j1 == n || a[i1][j1] || dis[i1][j1] != -1) continue;
            dis[i1][j1] = dis[i][j] + 1;
            q.push({i1, j1});
        }
    }
    cout<<dis[n - 1][n - 1];
    return 0;
}