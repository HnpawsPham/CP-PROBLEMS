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

int n;
int special[4];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "dis", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < 4; i++) 
        cin>>special[i];
    sort(special, special + 4);

    int dis[n + 1][n + 1];
    const int oo = 1e7 + 5;
    
    for(int i = 1; i <= n; i++){
        dis[i][i] = 0;
        for(int j = 1; j <= n; j++)
            if(i != j) dis[i][j] = oo;
    }

    int u, v, w;
    while(cin>>u>>v>>w)
        dis[u][v] = dis[v][u] = min(w, dis[u][v]);

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++){
                dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
            }

    int res = oo;
    do{
        for(int i = 1;i <= n; i++)
            for(int j = 1; j <= n; j++)
                res = min(res, dis[i][special[0]] + dis[i][special[1]] 
                             + dis[j][special[2]] + dis[j][special[3]] + dis[i][j]);
    } while(next_permutation(special, special + 4));

    cout<<res;
    return 0;
}