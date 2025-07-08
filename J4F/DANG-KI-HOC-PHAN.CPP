#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define pii pair<int, int>
#define fi first
#define se second

int n, k;
const int maxn = 2e5;
pii a[maxn];

bool check(ll x){
    ll sum = a[0].se;

    for(int i = 1; i < n; i++){
        if(sum >= k) return 1;

        if(a[i].fi - a[i - 1].fi <= x)
            sum += a[i].se;

        else sum = a[i].se;
    }
    return sum >= k;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    int maxx = 0, minn = INT_MAX;
    for(int i = 0; i < n; i++) {
        cin>>a[i].fi;
        maxx = max(maxx, a[i].fi);
        minn = min(minn, a[i].fi);
    }
    for(int i = 0; i < n; i++) cin>>a[i].se;

    sort(a, a + n);
    ll l = 0, r = maxx - minn, mid;

    while(l <= r){
        mid = (l + r) / 2;

        if(check(mid)) 
            r = mid - 1;

        else l = mid + 1;
    }
    cout<<l;
    return 0;
}