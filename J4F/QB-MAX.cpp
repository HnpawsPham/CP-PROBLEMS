#include <iostream>
#include <vector>
using namespace std;
#define el "\n"

int n, m;
const int maxn = 105;
const int INF = 1e5 + 5;
int a[maxn][maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin>>a[i][j];
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -INF));
    for(int i = 1; i <= n; i++) dp[i][1] = a[i][1];

    for(int j = 2; j <=m; j++)
        for(int i = 1; i <= n; i++){
            dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[i][j]);

            if(i > 1) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i][j]);
            if(i < n) dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + a[i][j]);
        }
    
    int res = -INF;
    for(int i = 1; i <= n; i++) res = max(res, dp[i][m]);
    printf("%d\n", res);
    return 0;
}