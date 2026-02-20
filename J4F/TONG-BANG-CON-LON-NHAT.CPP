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

int n, m;
const ll oo = 1e12 + 5;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vector<vi> b(n + 1, vi(m + 1)), a;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin>>b[i][j];

    if(n > m){
        a.resize(m + 1, vi(n + 1));
        for(int j = 1; j <= m; j++) 
            for(int i = 1; i <= n; i++)
                a[j][i] = b[i][m - j + 1];
        swap(n, m);
    }
    else a = b;

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= m; j++) cout<<a[i][j]<<" ";
    //     cout<<el;
    // }

    ll res = -oo;
    for(int top = 1; top <= n; top++){
        ll col[m + 1] = {0};
        for(int bot = top; bot <= n; bot++){
            for(int j = 1; j <= m; j++)
                col[j] += a[bot][j];

            ll maxx = col[1], sum = col[1];
            for(int i = 2; i <= m; i++){
                sum = max(sum + col[i], col[i]);
                maxx = max(maxx, sum);
            }
            res = max(res, maxx);
        }   
    }
    cout<<res;
    return 0;
}

// 4 3
// 1 2 3
// 4 5 6
// 7 8 9
// 10 11 12