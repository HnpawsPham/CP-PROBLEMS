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
#define taskname "SORT"

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, t;
    int m;

    cin>>n>>m>>t;
    if(m == 1) return cout<<t, 0;

    ll lim[m];
    int k = m;
    memset(lim, -1, sizeof lim);
    for(ll i = n; k; i--)
        if(lim[i % m] == -1){
            k--;
            lim[i % m] = i;
        }

    for(int i = 0; i < m; i++){
        ll u1 = (i == 0 ? m : i);
        ll sz = (lim[i] - u1) / m + 1;
        if(sz >= t){
            cout<<u1 + 1LL * m * (t - 1);
            break;
        }
        t -= sz;
    }
    return 0;
}