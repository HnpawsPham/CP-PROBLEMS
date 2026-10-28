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

    int n, m;
    cin>>n>>m;
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    vector<vector<bool>> dp(m, vector<bool>(1024, 0)), tmp;

    dp[0][a[0][0]] = 1;
    for(int i = 0; i < n ;i++){
        for(int j = 0; j < m - 1; j++)
            for(int x = 0; x <= 1023; x++){
                if(!dp[j][x]) continue;
                dp[j + 1][x ^ a[i][j + 1]] = 1;
            }

        if(i < n - 1){
            tmp.assign(m, vector<bool>(1024, 0));
            for(int j = 0; j < m; j++)
                for(int x = 0; x <= 1023; x++)
                    if(dp[j][x]) 
                        tmp[j][x ^ a[i + 1][j]] = 1; 
            dp = tmp;
        }
    }

    for(int x = 0; x <= 1023; x++)
        if(dp[m - 1][x]) return cout<<x, 0;
    cout<<1023;
    return 0;
}

// 2 2
// 1 2
// 3 4