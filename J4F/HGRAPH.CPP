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
const int maxn = 1005;
int a[maxn][maxn];

int dy[4] = {-1, 0, 0, 1},
    dx[4] = {0, -1, 1, 0};

bool valid(int i, int j){
    return (i >= 0 && j >= 0 && i < n && j < m);
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
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];        
 
    queue<pii> q;
    int dis[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dis[i][j] = 1e7 + 5;

    q.push({0, 0});
    dis[0][0] = 0;

    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();

        if(i == n - 1 && j == m - 1)
            break;

        for(int x = 0; x < 4; x++){
            int i1 = i + dy[x];
            int j1 = j + dx[x];

            if(!valid(i1, j1)) continue;
            if(dis[i1][j1] > dis[i][j] + 1){
                dis[i1][j1] = dis[i][j] + 1;
                q.push({i1, j1});
            }
        }

        if(!a[i][j]) continue;
        for(int x = 0; x < 4; x++){
            int i1 = i + dy[x];
            int j1 = j + dx[x];

            while(valid(i1, j1)){
                if(dis[i1][j1] > dis[i][j] + 1){
                    dis[i1][j1] = dis[i][j] + 1;
                    q.push({i1, j1});
                }

                if(a[i1][j1]) break;
                i1 += dy[x];
                j1 += dx[x];
            }
        } 
    }
    cout<<dis[n - 1][m - 1];
    return 0;
}