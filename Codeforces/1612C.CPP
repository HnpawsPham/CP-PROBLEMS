#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc;

ll sum(ll a){
    return a * (a + 1) / 2;
}

int sol(){
    int n;
    ll k;
    cin>>n>>k;

    if(k > 1LL * n * n) return 2 * n - 1;

    ll l = 1, r = n, mid;
    if(sum(n) >= k){
        while(l <= r){
            mid = (l + r) / 2;
            
            if(sum(mid) < k) l = mid + 1;
            else r = mid - 1;
        }
        return l;
    }

    l = 1; r = n - 1;
    ll comp = k - sum(n);

    while(l <= r){
        mid = (l + r) / 2;

        if(sum(n - 1) - sum(n - 1 - mid) < comp) 
            l = mid + 1;
        else r = mid - 1;
    }
    return n + l;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }

    return 0;
}