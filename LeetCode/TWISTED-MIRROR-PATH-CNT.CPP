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

int dy[2] = {0, 1},
    dx[2] = {1, 0};
const int MOD = 1e9 + 7;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>a[i][j];

    int cnt[n][m];
    pii pos[n][m][2]; // 0 right 1 down
    for(int i = 0; i < n; i++)  
        for(int j = 0; j < m; j++)
            for(int x = 0; x < 2; x++){
                int d = x, posx = i, posy = j;
                pos[i][j][x] = {-1, -1};

                while(1){
                    int i1 = posx + dy[d];
                    int j1 = posy + dx[d];

                    if(i1 < 0 || j1 < 0 || i1 == n || j1 == m)
                        break;
                    
                    if(!a[i1][j1]){
                        pos[i][j][x] = {i1, j1};
                        break;
                    }

                    posx = i1;
                    posy = j1;
                    d = 1 - d;
                }
            }

    memset(cnt, 0, sizeof cnt);
    cnt[0][0] = 1;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(!cnt[i][j]) continue;

            for(int x = 0; x < 2; x++){
                auto [i1, j1] = pos[i][j][x];
                if(i1 != -1)
                    cnt[i1][j1] = (cnt[i1][j1] + cnt[i][j]) % MOD; 
            }   
        }
    cout<<cnt[n - 1][m - 1];
    return 0;
}

// 3 3
// 0 1 0
// 0 0 1
// 1 0 0