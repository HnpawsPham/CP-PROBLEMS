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

    vector<vll> p(n + 1, vll(m + 1, 0));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            p[i][j] = p[i - 1][j] + p[i][j - 1] + a[i - 1][j - 1] - p[i - 1][j - 1];

    for(int i = 1; i <= n; i++)
        if(p[i][m] == p[n][m] - p[i][m]) 
            return cout<<1, 0;
    
    for(int j = 1; j <= m; j++)
        if(p[n][j] == p[n][m] - p[n][j]) 
            return cout<<1, 0;
    cout<<0;
    return 0;
}

// 2 2
// 1 3
// 2 4

// 2 2
// 1 4 
// 2 3