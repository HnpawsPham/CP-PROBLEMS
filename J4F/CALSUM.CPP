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

const ll MOD = 1e9 + 7;
int a, n;

ll ppow(ll a, int b){
    if(b == 0) return 1;
    ll half = ppow(a, b / 2);
    if(b & 1) return half * half % MOD * a % MOD;
    return half * half % MOD;
}

ll sol(int n){
    if(n == 0) return 1;
    if(n % 2)
        return sol(n / 2) * (1 + ppow(a, n / 2 + 1)) % MOD;
    return (sol(n - 1) + ppow(a, n)) % MOD;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>n;
    cout<<sol(n);
    return 0;
}