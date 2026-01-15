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
// #define taskname "BAI1"

ll l, r, a, b;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>l>>r>>a>>b;
    ll diva = r / a - (l - 1) / a;
    ll divb = r / b - (l - 1) / b;
    ll gcd = __gcd(a, b);
    ll lcm = 1LL * a / gcd * 1LL * b;
    ll same = r / lcm - (l - 1) / lcm;
    cout<<1LL * diva + 1LL * divb - 1LL * same;
    return 0;
}