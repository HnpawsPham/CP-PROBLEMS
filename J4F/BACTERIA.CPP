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

    int n, m;
    cin>>n>>m;
    int a[n + 2][m + 2] = {0};
    for(int i = 1; i <= n;i ++)
        for(int j = 1; j <= m; j++) 
            cin>>a[i][j];

    int res[n + 1][m + 1] = {0};
    memset(res, 0, sizeof res);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            res[i + 1][j] = a[i][j] - res[i][j - 1] - res[i][j + 1] - res[i - 1][j];
        
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=m; j++)
            cout<<res[i][j]<<" ";
        cout<<el;
    }
    return 0;
}