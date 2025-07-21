#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define pii pair<int, int>
#define vi vector<int>
#define fi first
#define se second

int n, m, k;
const int maxn = 805;
int a[maxn][maxn] = {0};

int dy[4] = {-1 , 0, 0 , 1},
    dx[4] = {0, -1, 1, 0};

int dfs(int i, int j){
    int cnt = 1;
    a[i][j] = 0;

    for(int d = 0; d < 4; d++){
        int i1 = i + dy[d];
        int j1 = j + dx[d];

        if(i1 < 0 || i1 == n || j1 < 0 || j1 == m || !a[i1][j1]) continue;
        cnt += dfs(i1, j1);
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;

    while(k--){
        int x, y;
        cin>>x>>y;
        x--;
        y--;
        a[x][y] = 1;
    }

    int res = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j]){
                res = max(res, dfs(i, j));
            }
    cout<<res;
    return 0;
}