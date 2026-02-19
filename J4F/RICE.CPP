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

ll c;
int p, n1, n2, t1, t2;

bool check(ll x){
    return (x * p + x / n1 * t1 + x / n2 * t2 <= c);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>c>>p>>n1>>n2>>t1>>t2;
    ll l = 0, r = c / p;
    while(l <= r){
        ll mid = l + (r - l) / 2;
        if(check(mid))
            l = mid + 1;
        else r = mid - 1;
    }
    cout<<l - 1;
    return 0;
}