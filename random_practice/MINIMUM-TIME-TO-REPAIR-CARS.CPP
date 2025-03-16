#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, c;

bool sol(ll t, vector<int>& a){
    ll repaired = 0;
    
    for(int x : a){
        ll car = t / x;
        car = floor(sqrt(car));
        repaired += car;
    }
    return repaired >= c;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>c;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    ll l = 0, r = 1e9;

    while(l <= r){
        ll mid = l + (r - l)/2;
        if(sol(mid, a)) r = mid - 1;
        else l = mid + 1;
    }

    cout<<l;

    return 0;
}