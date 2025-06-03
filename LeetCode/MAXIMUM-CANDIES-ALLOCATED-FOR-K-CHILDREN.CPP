#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;
ll k;

bool check(ll mid, vector<ll>& a){
    ll cnt = 0;

    for(int i = 0; i < n; i++){
        cnt += a[i] / mid;
        if(cnt >= k) return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    ll l = 0, r = *max_element(a.begin(), a.end()), mid;
    ll res = 0;

    while(l <= r){
        mid = l + (r - l) / 2;

        if(check(mid, a)){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout<<res;
    return 0;
}