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

    int n, m, k;
    cin>>n>>m>>k;
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    vector<vi> p(n + 1, vi(m + 1, 0));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + a[i - 1][j - 1];

    int res = 0;
    // for(int sz = 1; sz <= min(n, m); sz++){
    //     bool found = 0;
    //     for(int i = sz; i <= n && !found; i++)
    //         for(int j = sz; j <= m && !found; j++){
    //             if(p[i][j] - p[i - sz][j] - p[i][j - sz] + p[i - sz][j - sz] <= k){
    //                 res = sz;
    //                 found = 1;
    //                 break;
    //             }
    //         }
    //     }

    int l = 1, r = min(n, m), mid;
    while(l <= r){
        mid = (l + r) / 2;
        bool ok = 0;

        for(int i = mid; i <= n && !ok; i++)
            for(int j = mid; j <= m && !ok; j++){
                if(p[i][j] - p[i - mid][j] - p[i][j - mid] + p[i - mid][j - mid] <= k){
                    ok = 1;
                    break;
                }
            }

        if(ok){
            l = mid + 1;
            res = mid;
        }
        else r = mid - 1;
    }
    cout<<res;
    return 0;
}

// 3 7 4
// 1 1 3 2 4 3 2
// 1 1 3 2 4 3 2
// 1 1 3 2 4 3 2

// 5 5 1
// 2 2 2 2 2
// 2 2 2 2 2
// 2 2 2 2 2
// 2 2 2 2 2
// 2 2 2 2 2