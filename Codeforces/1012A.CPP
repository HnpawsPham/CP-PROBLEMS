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
    int a[2 * n];
    for(int i = 0; i < 2 * n; i++) cin>>a[i];
    sort(a, a + n + n);

    ll res = LLONG_MAX;
    for(int i = 0; i < n; i++){
       if(i == 0) res = min(res, 1LL * (a[n - 1] - a[0]) * 1LL * (a[2 * n - 1] - a[n])); 
       else res = min(res, 1LL * (a[i + n - 1] - a[i]) * 1LL * (a[2 * n - 1] - a[0]));
    }
    cout<<res;
    return 0;
}