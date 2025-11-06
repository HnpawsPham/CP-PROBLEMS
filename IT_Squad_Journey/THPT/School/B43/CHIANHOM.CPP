
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

int tc = 1;
int n, m, l, r;
const int MOD = 918052004;
const int maxn = 2e5;
int a[maxn];
ll dp[maxn];

ll sol(int i){
    if(i == n) return 1;
    if(dp[i] != -1) return dp[i];
    dp[i] = 0;

    int cnt = 0;
    bool check[m + 1] = {0};
    for(int j = i; j < n; j++){
        if(!check[a[j]]){
            check[a[j]] = 1;
            cnt++;
        }

        if(cnt > r) break;

        if(l <= cnt && cnt <= r) 
            dp[i] = (dp[i] + sol(j + 1)) % MOD;
    }
    return dp[i];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cin>>n>>m>>l>>r;
        for(int i = 0; i < n; i++) cin>>a[i];
        memset(dp, -1, sizeof dp);
        cout<<sol(0) % MOD<<el;
    }
    return 0;
}

// 3
// 6 6 1 1
// 1 2 3 4 5 6
// 6 6 6 6
// 1 2 3 4 5 6
// 9 4 2 3
// 1 2 4 3 2 2 1 3 4