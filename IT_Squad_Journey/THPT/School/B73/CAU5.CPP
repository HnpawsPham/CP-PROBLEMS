#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
#define taskname "CAU5"

const ll oo = 1e9 + 5;
const int MOD = 1e9 + 7;
int k;

ll ppow(ll a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);
    if(b & 1) return half * half % MOD * a % MOD;
    return half * half % MOD;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>k;
    ll x = oo, len = oo;
    for(int i = 1; i < 10; i++){
        int rem = 0;
        ll sum = 0;
        for(int j = 1; j <= k; j++){
            rem = (rem * 10 + i) % k;
            sum = (sum * 10 + i) % MOD;

            if(rem) continue;
            if(j < len){
                len = j;
                x = sum;
            }
        }
    }
    cout<<x * ppow(k, MOD - 2) % MOD;
    return 0;
}