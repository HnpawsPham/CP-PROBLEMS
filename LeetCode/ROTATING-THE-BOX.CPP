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
    char a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    vector<vector<char>> res(m, vector<char>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            res[j][i] = a[n - i - 1][j];

    for(int i = m - 1; i >= 0; i--)
        for(int j = n - 1; j >= 0; j--){
            if(res[i][j] != '#') continue;

            int x = i;
            while(x + 1 < m && res[x + 1][j] == '.'){
                res[x++][j] = '.';
                res[x][j] = '#';
            }
        }    

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            cout<<res[i][j]<<" ";
        cout<<el;
    }
    return 0;
}

// 1 3
// # . #

// 2 4
// # . * .
// # # * . 