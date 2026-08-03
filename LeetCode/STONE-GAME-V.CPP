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

    int p[n + 1];
    p[0] = 0;
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i - 1];

    int dp[n + 1][n + 1];
    const int oo = 5e7 + 5;

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = -oo;

    for(int i = 0; i <= n; i++)
        dp[i][i] = 0;

    for(int len = 2; len <= n; len++)
        for(int i = 1; i + len - 1 <= n; i++){
            int j = i + len - 1;
            
            for(int mid = i; mid < j; mid++){
                int l = p[mid] - p[i - 1];
                int r = p[j] - p[mid];
                if(l < r)
                    dp[i][j] = max(dp[i][j], dp[i][mid] + l);
                else if(l > r) 
                    dp[i][j] = max(dp[i][j], dp[mid + 1][j] + r);
                else dp[i][j] = max(dp[i][j], max(dp[i][mid], dp[mid + 1][j]) + l);
            }
        }
    cout<<dp[1][n];
    return 0;
}

// 6
// 6 2 3 4 5 5