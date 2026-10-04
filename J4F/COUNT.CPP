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

ll lcm(ll a, ll b){
    return a * b / __gcd(a, b);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, a, b, c;
    while(cin>>n>>a>>b>>c){
        ll sum = n / lcm(a, b) + n / lcm(b, c) + n / lcm(a, c);
        sum -= n / lcm(lcm(a, b), c) * 3;
        cout<<sum<<el;
    }
    return 0;
}