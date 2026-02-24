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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int a[m];
    for(int i = 0; i < m; i++) cin>>a[i];
    
    int w[n + 1][n + 1];
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) cin>>w[i][j];

    const int oo = 1e9 + 15;
    vector<vi> dis(n + 1, vi(n + 1, oo));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            dis[i][j] = w[i][j];

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);

    ll res = dis[1][a[0]];
    for(int i = 1; i < m; i++)
        res += dis[a[i - 1]][a[i]];
    cout<<res + dis[a[m - 1]][n];
    return 0;
}