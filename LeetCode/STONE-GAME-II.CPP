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

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    const int oo = 1e6 + 5;
    const int maxm = 202; 

    int dp[n + 1][maxm];
    memset(dp, 0, sizeof dp);

    int s = 0;
    for(int i = n - 1; i >= 0; i--){
        s += a[i];

        for(int m = 1; m <= n; m++)
            for(int j = 1; j <= 2 * m; j++){
                if(i + j < n)
                    dp[i][m] = max(dp[i][m], s - dp[i + j][max(m, j)]);
                else dp[i][m] = s;
            }
    }
    cout<<dp[0][1];
    return 0;
}

// 5
// 2 7 9 4 4