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
#define taskname "LUCKY"

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    ll k;
    cin>>n>>k;
    ll a[n + 5];
    memset(a, 0, sizeof a);
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);

    ll cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += upper_bound(a + i, a + n, -k - a[i]) - lower_bound(a + i, a + n, -k - a[i]);
        cnt += upper_bound(a + i, a + n, k - a[i]) - lower_bound(a + i, a + n, k - a[i]);
    }
    cout<<cnt;
    return 0;
}