#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    ll maxx = -LLONG_MAX;
    while(n--){
        ll x; cin>>x;
        maxx = max(x, maxx);
    }
    cout<<maxx;
    return 0;
}