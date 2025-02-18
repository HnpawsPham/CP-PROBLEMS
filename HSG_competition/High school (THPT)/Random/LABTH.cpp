#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>

int m, n;
const int maxn = (int)1e3 + 5;
char a[maxn][maxn];

int dx[] = {1, 0, 0, - 1},
    dy[] = {0, 1, -1, 0};

string dir = "SEWN";

bool dfs(int i, int j, string path){
    if(i == n || j == m || i == 1 || j == 1){
        cout<<path;
        return 1;
    }
    a[i][j] = '#';
    
    for(int x = 0; x < 4; x++){
        int i1 = i + dx[x];
        int j1 = j + dy[x];

        if(i1 < 1 || j1 < 1 || i1 > n || j1 > m || a[i1][j1] == '#') continue;
        if (dfs(i1, j1, path + dir[x])) return 1;
    }
    return 0;
}

int main(){
    freopen(".\\txt\\LABTH.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int x, y;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=m;j++){
            cin>>a[i][j];
            if(a[i][j] == '*'){
                x = i;
                y = j;
            }
        }
    }

    dfs(x, y, "");

    return 0;
}