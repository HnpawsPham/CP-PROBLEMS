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

const ll oo = 1e16;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<ll> minn(k, oo);
    ll p = 0, res = -oo;
    minn[0] = 0;

    for(int i = 0; i < n; i++){
        p += a[i];

        int mod = (i + 1) % k;
        res = max(res, p - minn[mod]);
        minn[mod] = min(minn[mod], p);
    }
    cout<<res;
    return 0;
}

// 2 1
// 1 2

// 5 4
// -1 -2 -3 -4 -5

