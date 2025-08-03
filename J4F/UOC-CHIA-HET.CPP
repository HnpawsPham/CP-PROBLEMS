#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'

ll n, a, b, c;

ll lcm(ll a, ll b){
    if(a == -1 || b == -1) return -1;

    ll gcd = __gcd(a, b);

    if(a / gcd > n / b) return -1;
    return a / gcd * b;
}

int cntdiv(ll x){
    if(x == -1) return 0;
    if(n % x) return 0; 

    ll m = n / x;
    int cnt = 0;

    for(ll i = 1; i <= sqrt(m); i++){
        if(m % i == 0){
            cnt += 2;
            if(i == m / i) cnt--;
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>a>>b>>c;

    ll gab = lcm(a, b);
    ll gac = lcm(a, c);
    ll gbc= lcm(b, c);
    ll gabc = lcm(a, lcm(b, c));
    
    cout<<cntdiv(gab) + cntdiv(gac) + cntdiv(gbc) - 2 * cntdiv(gabc);
    return 0;
}