// PREVENT OVERFLOW
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

ll n, a, b;

ll safe_mul(ll a, ll b){
    if(a == 0 || b == 0) return 0;
    if(a > n / b) return n + 1;
    return a * b;
}
// neu dung ppow thi cung nen ap dung safe_mul

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>a>>b;
    ll tmp = safe_mul(a, b);
    cout<<(tmp <= n ? tmp : -1);

    return 0;
}