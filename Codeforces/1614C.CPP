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
const int MOD = 1e9 + 7;

int sol(){
    int n, m;
    cin>>n>>m;
    
    int s = 0;
    while(m--){
        int l, r, x;
        cin>>l>>r>>x;
        s |= x;
    }

    ll pow2 = 1;
    for(int i = 1; i < n; i++)
        pow2 = pow2 * 2 % MOD;

    ll res = 0;
    for(int i = 0; i < 31; i++)
        if(1 & (s >> i)){
            ll x = 1;
            for(int j = 0; j < i; j++)
                x = x * 2 % MOD;
            res = (res +  pow2 * x % MOD) % MOD;
        }
    return res;
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