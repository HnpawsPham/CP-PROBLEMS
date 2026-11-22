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
#define mask(i, j) ((i >> j) & 1)
//#define taskname ""

int tc = 1;
int n, m;
const int maxn = 32;
ll dp[maxn][maxn];

bool check(int mask1, int mask2){
    for(int i = 1; i < m; i++){
        int sum = mask(mask1, i) + mask(mask1, i - 1);
        sum += mask(mask2, i) + mask(mask2, i - 1);

        if(!sum || sum == 4)
            return 0;
    }
    return 1;
}

ll sol(){
    cin>>n>>m;
    if(n < m) swap(n, m);

    memset(dp, 0, sizeof dp);
    int sz = (1 << m);

    for(int i = 0; i < sz ;i++)
        dp[0][i] = 1;

    for(int i = 1; i < n; i++){
        for(int mask1 = 0; mask1 < sz; mask1++){
            for(int mask2 = 0; mask2 < sz; mask2++)
                if(check(mask1, mask2))
                    dp[i][mask1] += dp[i - 1][mask2];
        }
    }

    ll res = 0;
    for(int i = 0; i < sz; i++)
        res += dp[n - 1][i];
    return res;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}