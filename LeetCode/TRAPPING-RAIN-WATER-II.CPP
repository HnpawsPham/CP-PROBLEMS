#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int, int>
#define piii pair<int, pii>
#define fi first
#define se second

int n, m;
const int maxn = 205;
int dy[4] = {-1, 1, 0, 0},
    dx[4] = {0, 0, 1, -1};
int a[maxn][maxn];
bool check[maxn][maxn];

int bfs(){
    int sum = 0;
    priority_queue<piii, vector<piii>, greater<piii>> pq;
  
    for (int i = 0; i < n; i++) {
        pq.push({a[i][0], {i, 0}});
        pq.push({a[i][m - 1], {i, m - 1}});
        check[i][0] = check[i][m - 1] = 1;
    }

    for (int j = 0; j < m; j++) {
        pq.push({a[0][j], {0, j}});
        pq.push({a[n - 1][j], {n - 1, j}});
        check[0][j] = check[n - 1][j] = 1;
    }

    while(!pq.empty()){
        auto [h, cur] = pq.top();
        pq.pop();
        auto [i, j] = cur;

        for(int x = 0; x < 4; x++){
            int i1 = i + dy[x];
            int j1 = j + dx[x];

            if(i1 < 0 || j1 < 0 || i1 == n || j1 == m || check[i1][j1]) continue;
            
            sum += max(0, h - a[i1][j1]);
            pq.push({max(a[i1][j1], h), {i1, j1}});
            check[i1][j1] = 1;
        }
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];
    
    memset(check, 0, sizeof(check));
    cout<<bfs();
    return 0;
}