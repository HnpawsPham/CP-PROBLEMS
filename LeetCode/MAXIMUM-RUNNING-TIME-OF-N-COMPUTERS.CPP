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

int n, m;

bool check(ll t, const vector<int>& a){
    ll sum = 0;
    for(int x : a) sum += min(1LL * x, t);
    return sum >= t * 1LL * m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    ll l = 0, r = 1e14 + 5, mid;
    while(l <= r){
        mid = l + (r - l) / 2;
        if(check(mid, a)) l = mid + 1;
        else r = mid - 1;
    }
    cout<<l - 1;
    return 0;
}

// 3 2
// 3 3 3

// 4 2
// 1 1 1 1

