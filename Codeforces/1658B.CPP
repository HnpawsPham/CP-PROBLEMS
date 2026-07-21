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
const int MOD = 998244353;

ll fact(int x){
    if(x <= 1) return 1;
    return x % MOD * fact(x - 1) % MOD;
}

ll sol(){
    int n;
    cin>>n;
    if(n % 2) return 0;
    ll x = fact(n / 2);
    return x % MOD * x % MOD;
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
        cout<<sol()<<el;
    }
    return 0;
}