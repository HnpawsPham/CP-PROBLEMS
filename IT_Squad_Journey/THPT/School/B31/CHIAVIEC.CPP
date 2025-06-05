#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

ll a, b, c ,d;

ll __lcm(ll x, ll y){
    return abs(x / __gcd(x, y) * y); 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>b>>c>>d;

    ll down = __lcm(b, d);
    a *= down / b;
    c *= down / d;

    ll up = a + c;
    ll gcd = __gcd(up, down);

    cout<<up / gcd<<" "<<down / gcd<<el;

    up = a - c;
    gcd = __gcd(up, down);

    cout<<abs(up / gcd)<<" "<<abs(down/ gcd);
    return 0;
}