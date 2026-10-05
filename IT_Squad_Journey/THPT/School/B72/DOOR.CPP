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
#define taskname "DOOR"

int n, s;
const int maxn = 1e6 + 5;
const int MOD = 998244353;
int a[maxn];

namespace sub1{
    void sol(){
        vll p;
        ll res = 0;

        for(int mask = 0; mask < (1 << (n / 2)); mask++){
            ll sum = 0;
            for(int i = 0; i < n / 2 && sum <= s; i++)
                if((mask >> i) & 1)
                    sum += a[i];
            if(sum <= s) p.push_back(sum);
        }
        sort(p.begin(), p.end());

        for(int mask = 0; mask < (1 << (n - n / 2)); mask++){
            ll sum = 0;
            for(int i = 0; i < n - n / 2 && sum <= s; i++)
                if((mask >> i) & 1)
                    sum += a[i + n / 2];

            if(sum <= s){
                int t = s - sum;
                res = (res + (upper_bound(p.begin(), p.end(), t) - lower_bound(p.begin(), p.end(), t) + MOD) % MOD) % MOD;
            }
        }
        cout<<res;
    }
}

namespace sub2{
    ll dp[maxn];
    void sol(){
        memset(dp, 0, sizeof dp);
        dp[0] = 1;

        for(int i = 0; i < n; i++)
            for(int j = s; j >= a[i]; j--)
                dp[j] = (dp[j] + dp[j - a[i]]) % MOD;;
        cout<<dp[s];
    }
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>s;
    for(int i = 0; i < n; i++) cin>>a[i];

    if(n * s <= 5e7) sub2::sol();
    else sub1::sol();
    return 0;
}