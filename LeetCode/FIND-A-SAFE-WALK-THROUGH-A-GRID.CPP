#include <bits./stdc++.h>
using namespace std;
#define el "\n"

int n, m, health;
const int maxn = 55;
int a[maxn][maxn];
bool maxx[maxn][maxn] = {-1};
bool ok = 0;

int dy[4] = {-1, 0, 0, 1},
    dx[4] = {0, -1, 1, 0};

void dfs(int i, int j, int health){
    if(health <= maxx[i][j]) return;
    maxx[i][j] = health;
    health -= a[i][j];

    if(health <= 0) return;

    if(i == n - 1 && j == m - 1 && health > 0){
        ok = 1;
        return;
    }

    for(int x = 0; x < 4; x++){
        int i1 = i + dy[x];
        int j1 = j + dx[x];

        if(i1 < 0 || j1 < 0 || i1 == n || j1 == m || check[i1][j1] || health < 1) continue;
        dfs(i1, j1, health);
        if(ok) return;
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>health;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    dfs(0, 0, health);
    cout<<ok;

    return 0;
}