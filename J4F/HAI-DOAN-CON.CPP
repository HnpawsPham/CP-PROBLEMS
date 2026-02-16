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

const ll oo = 1e15 + 5;

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
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    if(n == 2) return cout<<a[1] + a[2], 0;

    ll pl[n + 1], pr[n + 2], maxl[n + 1], maxr[n + 2];
    pl[0] = pr[n + 1] = maxl[0] = maxr[n + 1] = -oo;

    for(int i = 1; i <= n; i++){
        pl[i] = max(pl[i - 1] + a[i], 1LL * a[i]);
        maxl[i] = max(maxl[i - 1], pl[i]);
    }
    for(int i = n; i > 0; i--){
        pr[i] = max(pr[i + 1] + a[i], 1LL * a[i]);
        maxr[i] = max(maxr[i + 1], pr[i]);
    }

    ll res = -oo;
    for(int i = 1; i < n; i++)
        res = max(res, maxl[i] + maxr[i + 1]);
    cout<<res;
    return 0;
}