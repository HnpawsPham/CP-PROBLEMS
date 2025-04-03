#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    ll res = 0, maxx = 0, diff = 0;
    for(ll x : a){
        res = max(res, diff * x);
        diff = max(diff, maxx - x);
        maxx = max(maxx, x);
    }
    cout<<res;
    return 0;
}