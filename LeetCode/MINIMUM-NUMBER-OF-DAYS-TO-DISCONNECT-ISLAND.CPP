#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m;
const int maxn = 33;
int dy[4] = {-1, 0, 0, 1},
    dx[4] = {0, -1, 1, 0};
bool check[maxn][maxn];

bool valid(int i, int j){
    if(i < 0 || j < 0 || i == n || j == m || check[i][j]) return 0;
    return 1;
}

void dfs(int i, int j, const vector<vi>& a){
    check[i][j] = 1;

    for(int x = 0; x < 4; x++){
        int i1 = i + dy[x];
        int j1 = j + dx[x];

        if(valid(i1, j1) && a[i1][j1]) 
            dfs(i1, j1, a);
    }
    return;
}

bool is_connect(const vector<vi>& a){
    bool found = 0, has1 = 0;
    memset(check, 0, sizeof check);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] && !check[i][j]){
                if(found) return 0;
                found = has1 = 1;
                dfs(i, j, a);
            }
    return has1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vector<vi> a(n, vi(m));
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) cin>>a[i][j];

    if(!is_connect(a)) return cout<<0, 0;

    for(int i = 0; i < n; i++)  
        for(int j = 0; j < m; j++)
            if(a[i][j]){
                a[i][j] = 0;
                if(!is_connect(a)) return cout<<1, 0;
                a[i][j] = 1;
            }
    cout<<2;
    return 0;
}

// 3 4
// 0 1 1 0
// 0 1 1 0
// 0 0 0 0