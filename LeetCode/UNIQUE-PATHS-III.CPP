#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define vb vector<bool>
#define fi first
#define se second
//#define taskname ""

int n, m, u, v;

int dy[4] = {-1, 0, 1, 0},
    dx[4] = {0, -1, 0, 1};

bool ok(const vector<vb>& check){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!check[i][j]) return 0;
    return 1;
}

int sol(int i, int j, vector<vb>& check){
    if(i == u && j == v){
        if(ok(check)) return 1;
        return 0;
    }

    check[i][j] = 1;

    int res = 0;
    for(int x = 0; x < 4; x++){
        int i1 = i + dy[x];
        int j1 = j + dx[x];
        if(i1 < 0 || j1 < 0 || i1 == n || j1 == m || check[i1][j1])
            continue;

        check[i1][j1] = 1;
        res += sol(i1, j1, check);
        check[i1][j1] = 0;
    }
    return res;
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
    int stx, sty;
    vector<vi> a(n, vi(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>a[i][j];
            
    vector<vb> check(n, vb(m, 0));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(a[i][j] == -1) 
                check[i][j] = 1;
            else if(a[i][j] == 2){
                u = i;
                v = j;
            }
            else if(a[i][j] == 1){
                stx = i;
                sty = j;
            }
        }

    cout<<sol(stx, sty, check);
    return 0;
}

// 3 4
// 1 0 0 0
// 0 0 0 0
// 0 0 2 -1