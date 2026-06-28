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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n][n];
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) cin>>a[i][j];

    int w[n + 1][n + 1] = {0}, b[n + 1][n + 1] = {0};
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            w[i][j] = w[i - 1][j] + w[i][j - 1] - w[i - 1][j - 1];
            b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
            if((i + j) % 2 == 0) w[i][j] += a[i - 1][j - 1];
            else b[i][j] += a[i - 1][j - 1];
        }

    int q;
    cin>>q;
    while(q--){
        int x, y, u, v;
        cin>>x>>y>>u>>v;
        cout<<abs(w[u][v] - w[u][y - 1] - w[x - 1][v] + w[x - 1][y - 1] - (b[u][v] - b[u][y - 1] - b[x - 1][v] + b[x - 1][y - 1]))<<el;
    }
    return 0;
}