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

int n;
const int maxn = 1 << 16;
int a[20][20];
ll w[maxn], dp[maxn];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin>>a[i][j];

    memset(w, 0, sizeof w);
    for(int mask = 0; mask < (1 << n); mask++){
        ll sum = 0;
        for(int i = 0; i < n; i++){
            if((mask >> i) & 1)
                for(int j = i + 1; j < n; j++)
                    if((mask >> j) & 1)
                        sum += a[i][j];
        }
        w[mask] = dp[mask] = sum;
    }

    for(int mask = 0; mask < (1 << n); mask++)
        for(int sub = mask; sub > 0; sub = (sub - 1) & mask)
            dp[mask] = max(dp[mask], dp[sub] + dp[mask ^ sub]);
    cout<<dp[(1 << n) - 1];
    return 0;
}