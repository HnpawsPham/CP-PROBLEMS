#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
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

    int n, k;
    cin>>n>>k;
    pli a[n + 1] = {{0, -1}};
    for(int i = 1; i <= n; i++){
        cin>>a[i].fi;
        a[i].fi += a[i - 1].fi;
        a[i].se = i;
    }
    sort(a, a + n + 1);

    int res = -1, j = 0, l = n + 5;
    for(int i = 0; i <= n; i++){
        while(j <= n && a[i].fi - a[j].fi >= k)
            l = min(l, a[j++].se);

        if(a[i].se > l)
            res = max(res, a[i].se - l);
    }
    cout<<res;
    return 0;
}