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
#define taskname "CAU5"

int n;
const int maxn = 2e5 + 5;
int a[maxn];
const int MOD = 1e9 + 7;

namespace sub2{
    ll dp[maxn] = {0};

    ll sol(){
        ll res = 0;
        for(int i = 1; i <= n; i++){
            dp[i] = 1;

            for(int j = 1; j < i; j++){
                if(a[i] > a[j]) 
                    dp[i] = (dp[i] + dp[j]) % MOD;
            }
            res = (res + dp[i]) % MOD;
        }
        return res;
    }
};

namespace sub3{
    ll t[maxn] = {0};
    unordered_map<int, int> mp;

    void update(int i, ll val){
        while(i <= n){
            t[i] += val;
            i += (i & -i);
        }
        return;
    }

    ll query(int i){
        ll sum = 0;
        while(i > 0){
            sum += t[i];
            i -= (i & -i);
        }
        return sum;
    }

    void prepare(){
        memset(t, 0, sizeof t);

        vi b;
        for(int i = 1; i <= n; i++)
            b.push_back(a[i]);

        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());

        for(int i = 1; i <= b.size(); i++)
            mp[b[i - 1]] = i;
    }

    ll sol(){
        prepare();

        ll res = 0;
        for(int i = 1; i <= n; i++){
            ll dp = (1 + query(mp[a[i]] - 1)) % MOD;
            update(mp[a[i]], dp);
            res = (res + dp) % MOD;
        }
        return res;
    }
};

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i];

    if(n <= 2005)
        cout<<sub2::sol();
    else cout<<sub3::sol();
    return 0;
}