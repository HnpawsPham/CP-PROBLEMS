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

int tc = 1;

int sol(){
    int n, m, x, y;
    cin>>n>>m>>x>>y;
    char a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    int res = 0;
    if(m == 1){
        for(int i = 0; i < n; i++) 
            res += (a[i][0] == '.') * x;
        return res;
    }

    for(int i = 0; i < n; i++)
        for(int j = 1; j < m; j++){
            if(j == 1 && a[i][j] == '*' && a[i][j - 1] == '.'){
                res += x;
                continue;
            }

            if(a[i][j] == '*') continue;
            if(a[i][j - 1] == a[i][j]){
                res += min(2 * x, y);
                a[i][j] = '*';
            }
            else if(j < m - 1 && a[i][j + 1] == a[i][j]) 
                continue;
            else res += x;
        }
    return res;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}

// 1
// 2 3 10 9
// *.*
// ...