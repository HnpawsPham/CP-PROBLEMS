#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
//#define taskname ""

int n, d;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>d;
    pll a[n + 1];
    for(int i = 1; i <= n ;i++) 
        cin>>a[i].fi>>a[i].se;
    sort(a + 1, a + n + 1);

    ll p[n + 1] = {0};
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i].se;

    ll res = -5;
    for(int i = 1; i <= n; i++){
        int pos = lower_bound(a + 1, a + i + 1, make_pair(a[i].fi - d + 1, -1LL)) - a;
        if(pos > n) continue;

        res = max(res, p[i] - p[pos - 1]);
    }
    cout<<res;
    return 0;
}