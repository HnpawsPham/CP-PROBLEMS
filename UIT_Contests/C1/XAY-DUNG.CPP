#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, m, k;
const int maxn = 802;
int a[maxn][maxn] = {0};

int dy[4] = {-1, 0, 0, 1},
    dx[4] = {0, -1, 1, 0};

void dfs(int i, int j, int& cnt){
    a[i][j] = 0;
    cnt++;

    for(int x = 0; x < 4; x++){
        int i1 = i + dy[x];
        int j1 = j + dx[x];

        if(i1 < 1 || j1 < 1 || i1 > n || j1 > m || !a[i1][j1]) continue;

        dfs(i1, j1, cnt);
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    while(k--){
        int i, j;
        cin>>i>>j;
        a[i][j] = 1;
    }

    int res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            int cnt = 0;
            if(a[i][j]) dfs(i, j, cnt);

            res = max(res, cnt);
        }

    cout<<res;
    return 0;
}