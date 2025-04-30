#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, k;

bool check(ll val, vector<ll>& a){
    int i = 0, cnt = 0;

    while(i < n){
        if(a[i] <= val){
            i += 2;
            cnt++;
        }
        else i++;
    }
    return cnt >= k;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    ll l = *min_element(a.begin(), a.end());
    ll r = *max_element(a.begin(), a.end());
    ll mid, res;

    while(l <= r){
        mid = l + (r - l) / 2;
        
        if(check(mid, a)){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout<<res;
    return 0;
}