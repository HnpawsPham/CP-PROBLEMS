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

int n, k;

bool check(const vi& a, ll t){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        int l = 0, r = k, mid, res = 0;

        while(l <= r){
            mid = (l + r) / 2;
            if(1LL * a[i] * (mid * (mid + 1) / 2LL) <= t){
                l = mid + 1;
                res = mid;
            }
            else r = mid - 1;
        }
        cnt += res;
    }
    return cnt >= k;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>k>>n;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    
    sort(a.begin(), a.end());
    ll l = 0, r = LLONG_MAX, mid;
    while(l <= r){
        mid = (l + r) / 2;
        if(check(a, mid)) 
            r = mid - 1;
        else l = mid + 1;
    }
    cout<<l;
    return 0;
}

// 4 3
// 2 1 1

// 10 4
// 3 2 2 4

// 5 1
// 1