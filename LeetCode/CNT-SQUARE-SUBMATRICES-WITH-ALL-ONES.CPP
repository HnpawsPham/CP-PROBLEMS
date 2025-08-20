#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    vector<vi> a(n, vi(m));
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) cin>>a[i][j];

    vector<vi> dp(n + 1, vi(m + 1, 0));

    int res = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(!a[i - 1][j - 1]) continue;

            dp[i][j] = min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
            res += dp[i][j];
        }
    cout<<res;
    return 0;
}

// 3 4
// 0 1 1 1
// 1 1 1 1
// 0 1 1 1

// 3 3
// 1 0 1
// 1 1 0
// 1 1 0