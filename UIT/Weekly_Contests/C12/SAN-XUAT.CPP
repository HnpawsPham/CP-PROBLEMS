#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

const int oo = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vi> c(n, vi(m));
    vector<vi> d(m, vi(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> c[i][j];

    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++)
            cin >> d[i][j];

    vector<vi> dp(n, vi(m, oo));
    vector<vi> pre(n, vi(m, -1));

    for (int j = 0; j < m; j++)
        dp[0][j] = c[0][j];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                int val = dp[i-1][k] + d[k][j] + c[i][j];
                if (val < dp[i][j]) {
                    dp[i][j] = val;
                    pre[i][j] = k;
                }
                else if (val == dp[i][j] && k < pre[i][j]) 
                    pre[i][j] = k;
            }
        }
    }

    int last = 0;
    int tmp = oo;
    for (int j = 0; j < m; j++) 
        if (dp[n-1][j] < tmp) {
            tmp = dp[n-1][j];
            last = j;
        }

    vi ans(n);
    int cur = last;
    for (int i = n-1; i >= 0; i--) {
        ans[i] = cur + 1;
        cur = pre[i][cur];
    }

    cout << tmp;
    for (int i = 0; i < n; i++)
        cout << " " << ans[i];

    return 0;
}
