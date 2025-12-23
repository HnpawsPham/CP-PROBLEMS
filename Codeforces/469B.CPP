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

int n, m, l, r;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>l>>r;
    pii a[n], b[m];
    for(int i = 0; i < n; i++) cin>>a[i].fi>>a[i].se;
    for(int i = 0; i < m; i++) cin>>b[i].fi>>b[i].se;

    int res = 0;
    for(int t = l; t <= r; t++){
        bool ok = 0;
        for(pii x : b)
            for(pii y : a)
                if(max(x.fi + t, y.fi) <= min(x.se + t, y.se)){
                    ok = 1;
                    break;
                }
        res += ok;
    }
    cout<<res;
    return 0;
}

// 3 6 25 785
// 273 275
// 391 397
// 775 783
// 84 89
// 348 354
// 480 483
// 552 556
// 711 716
// 838 844