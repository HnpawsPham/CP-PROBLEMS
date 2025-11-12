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

int n, m, q, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>q>>k;
    pii a[q];
    for(int i = 0; i < q; i++) cin>>a[i].fi>>a[i].se;
    // int a[n + 1][m + 1] = {0};
    // while(q--){
    //     int x, y;
    //     cin>>x>>y;
    //     a[x][y] = 1;
    // }

    ll res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            for(int r = i; r <= n; r++)
                for(int c = j; c <= m; c++){
                   int cnt = 0;
                   
                    for(auto x : a)
                        if(x.fi >= i && x.fi <= r && x.se >= j && x.se <= c)
                            cnt++;
                    // for(int ii = i; ii <= r; ii++)
                    //     for(int jj = j; jj <= c; jj++)
                    //         cnt += a[ii][jj];
                    res += cnt >= k;
                }
    cout<<res;
    return 0;
}