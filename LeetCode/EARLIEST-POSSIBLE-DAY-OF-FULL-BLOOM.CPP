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
    int plant[n], grow[n];
    for(int i = 0; i < n; i++) cin>>plant[i];
    for(int i = 0; i < n; i++) cin>>grow[i];

    pii a[n];
    for(int i = 0; i < n; i++){
        a[i].fi = grow[i];
        a[i].se = plant[i];
    }
    sort(a, a + n, greater<pii>());

    int t = 0, res = 0;
    for(int i = 0; i < n; i++){
        t += a[i].se;
        res = max(res, t + a[i].fi);
    }
    cout<<res;
    return 0;
}