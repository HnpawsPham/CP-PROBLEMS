#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

int n, m; 
ll res = -1;
const int MOD = 1e9 + 7;
const int oo = 1e4 + 5;
int dx[2] = {1, 0},
    dy[2] = {0, 1};

int mulmod(int x, int y){
    x = (x % MOD + MOD) % MOD;
    y = (y % MOD + MOD) % MOD;
    return x * y % MOD;
}

void dfs(int i, int j, ll mul, const vector<vi>& a){
    if(i == n - 1 && j == m - 1){
        res = max(res, mul);
        return;
    }

    for(int x = 0; x < 2; x++){
        int i1 = i + dy[x];
        int j1 = j + dx[x];
        if(i1 < n && j1 < m)
            dfs(i1, j1, mul * 1LL * a[i1][j1], a);
    }
    return;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vector<vi> a(n, vi(m));
    for(int i = 0; i < n; i++)  
        for(int j = 0; j < m; j++) cin>>a[i][j];

    // dfs(0, 0, a[0][0], a);
    // cout<<(res % MOD + MOD) % MOD;
    
    vector<vll> maxx(n, vll(m, -oo)),
                minn(n, vll(m, oo));

    maxx[0][0] = minn[0][0] = a[0][0];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(i > 0){
                maxx[i][j] = max(max(maxx[i][j], maxx[i - 1][j]) * a[i][j], 
                                                 minn[i - 1][j] * a[i][j]);
                minn[i][j] = min(min(minn[i][j], minn[i - 1][j] * a[i][j]),
                                                 maxx[i - 1][j] * a[i][j]);
            }
            if(j > 0){
                maxx[i][j] = max(max(maxx[i][j], maxx[i][j - 1] * a[i][j]), 
                                                 minn[i][j - 1] * a[i][j]);
                minn[i][j] = min(min(minn[i][j], minn[i][j - 1] * a[i][j]), 
                                                 maxx[i][j - 1] * a[i][j]);
            }
        }
    if(maxx[n - 1][m - 1] < 0) return -1;
    cout<<(maxx[n - 1][m - 1] % MOD + MOD) % MOD;
    return 0;
}

// 3 3
// -1 -2 -3
// -2 -3 -3
// -3 -3 -2

// 3 3
// 1 -2 1
// 1 -2 1
// 3 -4 1