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

ll __lcm(ll a, ll b){
    return a * b / __gcd(a, b);
}

int n;

bool check(ll t, int k, const vector<int>& a){
    ll sum = 0;
    for(int i = 0; i < (1 << n); i++){
        ll lcm = 1;
        int cnt = 0;

        for(int j = 0; j < n; j++)
            if(1 & (i >> j)){
                cnt++;
                lcm = __lcm(lcm, a[j]);
            }

        if(cnt % 2) sum += t / lcm;
        else sum -= t / lcm;
    }
    return sum >= k;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin>>n>>k;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    ll l = 1, r = 1LL * *min_element(a.begin(), a.end()) * k;
    ll mid, res = r;
    while(l <= r){
        mid = l + (r - l) / 2;

        if(check(mid, k, a)){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout<<res;
    return 0;
}

// 3 3
// 3 6 9