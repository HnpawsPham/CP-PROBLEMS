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
//#define taskname ""

int tc = 1;
const ll oo = 1e18 + 5;

ll sol(){
    int n;
    ll h;
    cin>>n>>h;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    ll l = 0, r = oo, mid;
    while(l <= r){
        mid = l + (r - l) / 2;
        ll sum = mid; 
        for(int i = 1; i < n; i++)
            sum += min(1LL * a[i] - a[i - 1], mid);

        if(sum >= h) r = mid - 1;
        else l = mid + 1;
    } 
    return l;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}