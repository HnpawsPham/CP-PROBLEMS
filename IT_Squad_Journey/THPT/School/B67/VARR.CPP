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
#define taskname "VARR"

int n;
const int maxn = 2e5 + 5;
const ll MOD = 1e9 + 7;
int a[maxn], p[maxn];

namespace sub2{
    void sol(){
        ll res = 0;

        for(int i = 1; i <= n; i++)
            for(int j = i; j <= n; j++){
                int target = p[j] - p[i - 1];
                
                int cnt = 0;
                while(target > 0 && target % 2 == 0){
                    target /= 2;
                    cnt++;
                }
                res = (res + (1 << cnt)) % MOD;
            }
        cout<<res;
    }
}

namespace sub4{
    void sol(){
        ll res = 1LL * n * 1LL * (n + 1) / 2LL;

        for(int i = 1; i <= 20; i++){
            int k = (1 << i);
            if(k > p[n]) break;
            
            unordered_map<int, ll> cnt;
            cnt[0] = 1;

            for(int j = 1; j <= n; j++){
                res = (res + cnt[p[j] % k] * (1 << (i - 1)) % MOD) % MOD;
                cnt[p[j] % k] = (cnt[p[j] % k] + 1) % MOD;
            }    
        }
        cout<<res;
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

    cin>>n;
    for(int i = 0; i < n; i++) cin>>a[i];

    p[0] = 0;
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i - 1];

    if(n <= 5000)
        sub2::sol();
    else sub4::sol();
    return 0;
}