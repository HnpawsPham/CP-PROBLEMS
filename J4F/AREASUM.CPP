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

int n, m;
const int maxn = 1e5 + 5;
const ll MOD = 1e9 + 7;
int a[maxn], b[maxn];

ll calc(int sz, bool isx){
    ll p = 0, sum = 0;
    for(int i = 0; i < sz; i++){
        ll x = ((isx ? a[i] : b[i]) % MOD + MOD) % MOD;
        sum = (sum + (x * i % MOD - p + MOD) % MOD) % MOD;
        p = (p + x) % MOD;
    }
    return sum;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];

    ll sumx = calc(n, 1), sumy = calc(m, 0);
    cout<<sumx * sumy % MOD;
    return 0;
}

// 3 3
// 1 2 5
// 2 5 7

// 2 3
// 2 5
// 1 3 4