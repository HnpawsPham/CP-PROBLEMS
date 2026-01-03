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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    const int MOD = 1e9 + 7;
    int dp1 = 6, dp2 = 6;
    for(int i = 2; i <= n; i++){
        int tmp1 = dp1;
        dp1 = (2 * dp1 % MOD + 2 * dp2 % MOD) % MOD;
        dp2 = (2 * tmp1 % MOD + 3 * dp2 % MOD) % MOD;
    }
    cout<<(dp1 + dp2) % MOD;
    return 0;
}