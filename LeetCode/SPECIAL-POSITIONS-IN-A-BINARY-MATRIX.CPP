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

    vi row(n, 0), col(m, 0);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            row[i] += a[i][j];

    for(int j = 0; j < m; j++)
        for(int i = 0; i < n; i++)
            col[j] += a[i][j];

    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            if(!a[i][j]) continue;
            if(row[i] == 1 && col[j] == 1)
                cnt++;
        }
    cout<<cnt;
    return 0;
}

// 3
// 1 0 0
// 0 0 1
// 1 0 0

// 3
// 1 0 0
// 0 1 0
// 0 0 1