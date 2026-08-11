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
#define taskname "NARR"

int n;
ll k;
const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7;
int a[maxn], bit[maxn];

void update(int i, int val){
    while(i <= n){
        bit[i] += val;
        i += (i & -i);
    }
}

int query(int i){
    int sum = 0;
    while(i > 0){
        sum += bit[i];
        i -= (i & -i);
    }
    return sum;
}

namespace sub3{
    void sol(){
        vi mp;
        for(const int& x : a) mp.push_back(x);
        sort(mp.begin(), mp.end());
        mp.erase(unique(mp.begin(), mp.end()), mp.end());

        int pos[n + 1];
        for(int i = 1; i <= n; i++)
            pos[i] = lower_bound(mp.begin(), mp.end(), a[i - 1]) - mp.begin() + 1;

        ll dp[n + 1];
        memset(dp, 0, sizeof dp);
        dp[0] = 1;

        for(int i = 1; i <= n; i++){
            memset(bit, 0, sizeof bit);
            ll inv = 0;
            
            for(int j = i; j > 0; j--){
                inv += query(pos[j] - 1);
                if(inv > k) break;

                dp[i] = (dp[i] + dp[j - 1]) % MOD;
                update(pos[j], 1);
            }
        }
        cout<<dp[n];
    }
} 

namespace sub4{
    void sol(){
        vi mp;
        for(const int& x : a) mp.push_back(x);
        sort(mp.begin(), mp.end());
        mp.erase(unique(mp.begin(), mp.end()), mp.end());

        int pos[n + 1];
        for(int i = 1; i <= n; i++)
            pos[i] = lower_bound(mp.begin(), mp.end(), a[i - 1]) - mp.begin() + 1;

        ll dp[n + 1], p[n + 1];
        memset(dp, 0, sizeof dp);
        dp[0] = p[0] = 1;

        ll inv = 0;
        int l = 1;
        for(int i = 1; i <= n; i++){
            inv += i - l - query(pos[i]);
            update(pos[i], 1);

            while(inv > k){
                inv -= query(pos[l] - 1);
                update(pos[l], -1);
                l++;
            }

            dp[i] = (dp[i] + (p[i - 1] - (l >= 2 ? p[l - 2] : 0) + MOD) % MOD) % MOD;
            p[i] = (p[i - 1] + dp[i]) % MOD;
        }
        cout<<dp[n];
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

    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>a[i];

    if(n <= 3005) sub3::sol();
    else sub4::sol();
    return 0;
}