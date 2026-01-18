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

    vector<vi> row(n + 1, vi(m + 1, 0)), col(n + 1, vi(m + 1, 0));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            row[i][j] = row[i][j - 1] + a[i - 1][j - 1];
            col[i][j] = col[i - 1][j] + a[i - 1][j - 1];
        }

    int res = 1;
    for(int sz = 2; sz <= min(n, m); sz++){
        bool found = 0;
        for(int i = 0; i <= n - sz && !found; i++)
            for(int j = 0; j <= m - sz && !found; j++){
                bool ok = 1;
                int cur = row[i + 1][j + sz] - row[i + 1][j];

                for(int ii = i + 2; ii <= i + sz && ok; ii++)
                    if(row[ii][j + sz] - row[ii][j] != cur)
                        ok = 0;

                for(int jj = j + 1; jj <= j + sz && ok; jj++)
                    if(col[i + sz][jj] - col[i][jj] != cur)
                        ok = 0;

                int d1 = 0, d2 = 0;
                for(int ii = 0; ii < sz && ok; ii++){
                    d1 += a[i + ii][j + ii];
                    d2 += a[i + ii][j + sz - 1 - ii];
                }
                if(d1 != cur || d2 != cur) ok = 0;

                if(ok) found = 1;
            }

        if(found) res = sz;
    }
    cout<<res;
    return 0;
}

// 4 5
// 7 1 4 5 6
// 2 5 1 6 4
// 1 5 4 3 2
// 1 2 7 3 4