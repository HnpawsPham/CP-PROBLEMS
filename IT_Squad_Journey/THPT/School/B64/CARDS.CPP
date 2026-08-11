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
#define taskname "CARDS"

int n, k, m;
const ll MOD = 123456789;
ll cnte[105], cnto[105];

namespace sub1{
    void prep(){
        memset(cnte, 0, sizeof cnte);
        memset(cnto, 0, sizeof cnto);

        for(int i = 1; i <= k; i++){
            if(i % 2) 
                cnto[i % m] = (cnto[i % m] + 1) % MOD;
            else cnte[i % m] = (cnte[i % m] + 1) % MOD;
        }
    }

    void sol(){
        vll dp(m, 0);
        dp[0] = 1;

        for(int i = 1; i <= n; i++){
            vll tmp(m, 0);
            for(int j = 0; j < m; j++){
                if(!dp[j]) continue;

                for(int x = 0; x < m; x++){
                    int mod = (j + x) % m;
                    ll cnt = ((i % 2) ? cnto[x] : cnte[x]);

                    tmp[mod] = (tmp[mod] + dp[j] * cnt % MOD) % MOD;
                }
            }
            dp = tmp;
        }
        cout<<dp[0];
    }
}

namespace sub3{
    void prep(){
        memset(cnte, 0, sizeof cnte);
        memset(cnto, 0, sizeof cnto);

        for(int mod = 0; mod < m; mod++){
            for(int i = 1; i <= 2 * m; i++){
                if((i % m) != mod) continue;

                if(k >= i && (i % 2)){
                    cnto[mod] = ((k - i) / (2 * m) + 1) % MOD;
                    break;
                }
            }  

            for(int i = 1; i <= 2 * m; i++){
                if((i % m) != mod) continue;

                if(k >= i && !(i % 2)){
                    cnte[mod] = ((k - i) / (2 * m) + 1) % MOD;
                    break;
                }
            }  
        }
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

    cin>>n>>k>>m;
    if(n <= 1000 && k <= 1000){
        sub1::prep();
        sub1::sol();
    }
    else if(n <= 1000){
        sub3::prep();
        sub1::sol();
    }
    return 0;
}