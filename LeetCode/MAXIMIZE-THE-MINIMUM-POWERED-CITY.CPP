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

int n, r, k;
const ll maxn = 1e18;
ll sum;

bool check(ll t, int k, vi a){
    ll s = sum;

    for(int i = 0; i < n; i++){
        if(s < t){
            ll need = t - s;
            if(need > k) return 0;
            k -= need;

            a[min(i + r, n - 1)] += need;
            s += need;
        }

        if(i >= r) s -= a[i - r];
        if(i + r + 1 < n) s += a[i + r + 1];
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>r>>k;
    vi a(n);
    for(int i = 0; i< n; i++) cin>>a[i];

    ll L = 0, R = maxn, mid;
    sum = accumulate(a.begin(), a.begin() + r + 1, 0LL);

    while(L <= R){
        mid = (L + R) / 2;
        if(check(mid, k, a))
            L = mid + 1;
        else R = mid - 1;
    }
    cout<<L;
    return 0;
}

// 5 1 2
// 1 2 4 5 0