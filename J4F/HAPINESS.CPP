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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>m>>n;
    pii a[n];
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i].se>>a[i].fi;
        sum += a[i].se;
    }    
    sort(a, a + n);
    sum -= a[n - 1].se;

    ll res = 0;
    int cnt = 0;
    for(int i = 0; i < n - 1; i++){
        if((a[i].se >= a[n - 1].fi) || 
        (sum > a[n - 1].se + (m - cnt - 1) * a[n - 1].fi)){
            cnt++;
            res += a[i].se;
        }
        sum -= a[i].se;
    }

    if(cnt == m) cout<<res;
    else cout<<res + 1LL * a[n - 1].fi * 1LL * (m - cnt - 1) + 1LL * a[n - 1].se;
    return 0;
}
// 4 5
// 1 100
// 101 0
// 102 0
// 28 0
// 103 0