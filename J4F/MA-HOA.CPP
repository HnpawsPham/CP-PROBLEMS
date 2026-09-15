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

ll l, r, a, k;

namespace sub1{
    void sol(){
        int cnt = 0;
        for(int i = l; i <= r; i++)
            if((a * i % k) == 0) cnt++;
        cout<<cnt;
    }
}

namespace sub2{
    void sol(){
        ll x = k / __gcd(a, k);
        cout<<r / x - (l - 1) / x;
    }
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>l>>r>>a>>k;
    if(max(l, max(r, max(a, k))) <= 1e6)
        sub1::sol();
    else sub2::sol();
    return 0;
}