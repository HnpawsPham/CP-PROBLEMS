#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define piii pair<int, pii>
#define fi first
#define se second
//#define taskname ""

int n;
const int oo = 1005;
int dy[4] = {-1, 0, 1, 0},
    dx[4] = {0, 1, 0, -1};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int a[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin>>a[i][j];

    queue<pii> q;
    vector<vi> dis(n, vi(n, -1));

    for(int i =0; i <n; i++) 
        for(int j = 0; j < n; j++)
            if(a[i][j]){
                q.push({i, j});
                dis[i][j] = 0;
            }
        
    while(!q.empty()){
        auto [i, j] = q.front();
        q.pop();

        for(int x = 0; x < 4; x++){
            int i1 = i + dy[x];
            int j1 = j + dx[x];

            if(i1 < 0 || j1 < 0 || i1 == n || j1 == m || dis[i1][j1] == -1)
                continue;

            q.push({i1, j1});
            dis[i1][j1] = dis[i][j] + 1;
        }
    }

    priority_queue<piii> pq;
    pq.push({dis[0][0], {0, 0}});
    a[0][0] = 2;

    while(!pq.empty()){
        auto [w, pos] = pq.top();
        auto [i, j] = pos;
        pq.pop();

        if(i == j && i == n - 1) 
            return cout<<w, 0;

        for(int x = 0; x < 4; x++){
            int i1 = i + dy[x];
            int j1 = j + dx[x];

            if(i1 < 0 || j1 < 0 || i1 == n || j1 == n || a[i1][j1] == 2) continue;
            
            pq.push({min(w, dis[i1][j1]), {i1, j1}});
            a[i1][j1] = 2;
        }
    }
    cout<<dis[n - 1][n - 1];
    return 0;
}