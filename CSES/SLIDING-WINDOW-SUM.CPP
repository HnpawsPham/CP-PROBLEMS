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

int k, n, base, mul, add, MOD;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>base>>mul>>add>>MOD;
    ll a[n];
    a[0] = base;
    for(int i = 1; i < n; i++)
        a[i] = (a[i - 1] * mul + add) % MOD;

    ll sum = 0, res = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
        
        if(i + 1 < k) continue;
        res ^= sum;
        sum -= a[i - k + 1];
    }
    cout<<res;
    return 0;
}