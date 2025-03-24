#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define pll pair<ll, ll>
#define fi first
#define se second
#define vll vector<ll>

int n, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>k>>n;
    vector<vll> a(n, vll(2));
    ll res = 0, last = 0;

    for(int i = 0; i < n; i++)
        cin>>a[i][0]>>a[i][1];

    sort(a.begin(), a.end());

    for(vll v : a){
        ll l = v[0], r = v[1];

        if(l > last)
            res += (l - last - 1);

        last = max(last, r);
    }
    res += (k - last);
    cout<<res;
    return 0;
}