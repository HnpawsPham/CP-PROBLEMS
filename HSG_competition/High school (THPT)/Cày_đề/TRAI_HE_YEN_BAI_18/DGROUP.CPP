#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

ll n, m, k;

bool check(int x){
    return (1LL * 3 * x <= 1LL *  m + 1LL *  n - 1LL * k) && (x <= m && x <= n / 2);
}

ll bns(){
    ll l = 0, r = min(n / 2, m), res = 0;
    while(l <= r){
        ll mid = l + (r - l) / 2;
        if(check(mid)){
            res = max(res, mid);
            l = mid + 1;
        }
        else r = mid - 1;
    }
    return res;
}

int main(){
    freopen("DGROUP.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    cout<<bns();
    return 0;
}