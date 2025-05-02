#include <iostream>
using namespace std;
#define el "\n"

int n, m;
const int maxn = 105;
char a[maxn][maxn];

int dy[4] = {0, -1, 1, 0},
    dx[4] = {-1, 0, 0, 1};

void dfs(int i, int j){
    a[i][j] = '.';

    for(int x = 0; x < 4; x++){
        int i1 = i + dy[x];
        int j1 = j + dx[x];

        if(i1 < 0 || i1 == n || j1 < 0 || j1 == m || a[i1][j1] == '.') continue;

        a[i1][j1] = '.';
        dfs(i1, j1);
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] == '#'){
                dfs(i, j);
                cnt++;
            }
    cout<<cnt;

    return 0;
}
