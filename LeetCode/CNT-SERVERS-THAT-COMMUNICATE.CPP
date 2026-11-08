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
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    int col[m], row[n];
    memset(col, 0, sizeof col);
    memset(row, 0, sizeof row);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            row[i] += a[i][j];
    
    for(int j = 0; j < m; j++)
        for(int i = 0; i < n; i++)
            col[j] += a[i][j];

    int res = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] && (row[i] > 1 || col[j] > 1)) 
                res++;
    cout<<res;
    return 0;
}

// 2
// 1 0
// 0 1