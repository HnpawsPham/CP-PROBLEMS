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

    int n, m, x, y, k;
    cin>>n>>m>>x>>y>>k;
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    for(int i = x; i < x + k / 2; i++)
        for(int j = y; j < y + k; j++)
            swap(a[i][j], a[2 * x + k - i - 1][j]);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout<<a[i][j]<<" ";
        cout<<el;
    }
    return 0;
}

// 4 4 1 0 3
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16