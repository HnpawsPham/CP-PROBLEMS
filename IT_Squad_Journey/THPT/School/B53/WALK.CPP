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
#define taskname "WALK"

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, r;
    cin>>n>>r;
    int a[n] = {0};
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);

    ll cnt = 0;
    for(int i = 0; i < n; i++)
        cnt += n - (upper_bound(a, a + n, a[i] + r) - a);
    cout<<cnt;
    return 0;
}

// 4 4
// 1 3 5 8