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
#define taskname "SUMARR"

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, q;
    cin>>n>>m>>q;
    int a[n + 1][m + 1];
    memset(a, 0, sizeof a);

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin>>a[i][j];

    ll p[n + 1][m + 1];
    memset(p, 0, sizeof p);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            p[i][j] = p[i][j - 1] + p[i - 1][j] - p[i - 1][j - 1] + a[i][j];

    while(q--){
        int x, y, u, v;
        cin>>x>>y>>u>>v;
        cout<<p[u][v] - p[x - 1][v] - p[u][y - 1] + p[x - 1][y - 1]<<el;
    }
    return 0;
}