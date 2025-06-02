#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    cin>>a>>b;

    // ll res = 1LL * a / b;
    // res = max(res, (ll)INT_MIN);
    // res = min(res, (ll)INT_MAX);
    
    if(a == INT_MIN && b == -1) return cout<<INT_MAX, 0;

    ll res = 0;
    ll k = abs((ll)a);

    while(k >= abs((ll)b)){
        ll tmp = abs((ll)b), mul = 1;

        while(k >= tmp * 2){
            tmp *= 2;
            mul *= 2;
        }

        k -= tmp;
        res += mul;
    }
    if((a < 0) ^ (b < 0)) res = -res;
    cout<<res;

    return 0;
}