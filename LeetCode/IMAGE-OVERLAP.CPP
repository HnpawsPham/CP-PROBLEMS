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
    int a[n][n], b[n][n];
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++)
            cin>>a[i][j];
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>b[i][j];
    
    int ra[n], rb[n];
    for(int i = 0; i < n; i++){
        ra[i] = rb[i] = 0;

        for(int j = 0; j < n; j++){
            ra[i] = (ra[i] << 1) | a[i][j];
            rb[i] = (rb[i] << 1) | b[i][j];
        }
    }

    int res = 0;
    for(int i = -n + 1; i < n; i++){
        for(int j = -n + 1; j < n; j++){
            int sum = 0;
            for(int r = 0; r < n; r++){
                if(r + i < 0 || r + i >= n) continue;

                int cur = (j > 0 ? (ra[r] >> j) : (ra[r] << -j));
                sum += __builtin_popcount(cur & rb[r + i]);
            }
            res = max(res, sum);
        }
    }
    cout<<res;
    return 0;
}

// 3 
// 1 1 0
// 0 1 0
// 0 1 0
// 0 0 0
// 0 1 1
// 0 0 1