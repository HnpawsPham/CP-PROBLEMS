#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define piii pair<pii, int>
#define fi first
#define se second

struct pos{
    int i, j, k, d;
    bool ok; // = 1 neu tu mot o khac den
};

int n, m, sz;
const int maxn = 305;
string s, a[maxn];
bool check[maxn][maxn][maxn][2] = {0}; // k, i, j, ok
int dy[4] = {-1, 1, 0, 0},
    dx[4] = {0, 0, -1, 1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>sz>>s;
    for(int i = 0; i < n; i++) cin>>a[i];
    
    queue<pos> q;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            q.push({i, j, 0, 0});
            check[0][i][j][0] = 1;
        }

    while(!q.empty()){
        auto [i, j, k, d, ok] = q.front();
        q.pop();

        if(k == sz) return cout<<d, 0;

        if(ok && a[i][j] == s[k] && !check[k + 1][i][j][0]){
            check[k + 1][i][j][0] = 1;
            q.push({i, j, k + 1, d, 0});
        }

        for(int x = 0; x < 4; x++){
            int i1 = i + dy[x];
            int j1 = j + dx[x];
            if(i1 < 0 || j1 < 0 || i1 == n || j1 == m || check[k][i1][j1][1]) continue;
            check[k][i1][j1][1] = 1;
            q.push({i1, j1, k, d + 1, 1});
        }
    }
    return 0;
}

// 2 4 6
// DHDBBB
// DHAB
// ABBD
