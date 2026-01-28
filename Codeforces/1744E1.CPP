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

int tc = 1;

void sol(){
    ll a, b, c, d;
    cin>>a>>b>>c>>d;

    ll mul = 1LL * a * b;
    for(int x = a + 1; x <= c; x++){
        ll gcd = __gcd(1LL * x, mul);
        ll left = mul / gcd;
        ll y = (b / left + 1) * left;

        if(y <= d){
            cout<<x<<" "<<y<<el;
            return;
        }
    }
    cout<<"-1 -1"<<el;
    return;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        // cout<<sol()<<el;
        sol();
    }
    return 0;
}