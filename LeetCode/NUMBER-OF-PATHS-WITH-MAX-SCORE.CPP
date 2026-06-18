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

const int oo = 1e4 + 5;
const int MOD = 1e9 + 7;

int cost(char x){
    if('0' <= x && x <= '9')
        return x - '0';
    if(x == 'X') return -oo;
    return 0;
}

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
    string a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    int m = a[0].size(); 

    vector<vi> dp(n + 1, vi(m + 1, -oo)), 
    cnt(n + 1, vi(m + 1, 0));

    dp[n - 1][m - 1] = 0;
    cnt[n - 1][m - 1] = 1;

    for(int i = n - 1; i >= 0; i--)
        for(int j = m - 1; j >= 0; j--){
            dp[i][j] = max(dp[i][j], 
            max(dp[i + 1][j], max(dp[i][j + 1], dp[i + 1][j + 1])) + cost(a[i][j]));

            bool found = 0;
            for(pii x : vector<pii>{{i + 1, j}, {i, j + 1}, {i + 1, j + 1}})
                if(dp[i][j] == dp[x.fi][x.se] + cost(a[i][j])){
                    if(found) cnt[i][j] = (cnt[i][j] + cnt[x.fi][x.se]) % MOD;
                    else{
                        cnt[i][j] = cnt[x.fi][x.se];
                        found = 1;
                    }
                }
        }

    if(cnt[0][0] > 0 && dp[0][0] >= 0) 
        cout<<dp[0][0]<<" "<<cnt[0][0];
    else cout<<"0 0";
    return 0;
}

// 3
// E23 2X2 12S