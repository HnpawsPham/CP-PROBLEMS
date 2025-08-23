#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

int k;
string s1, s2;
int n;
vector<vi> dp;

bool check(int l) {
    if (l == 0)  return 1;
    if (l > n) return 0;

    for (int i = 0; i <= n; ++i) 
        for (int j = 0; j <= n; ++j) 
            dp[i][j] = 0;

    for (int i = 1; i <= n; ++i) 
        for (int j = 1; j <= n; ++j) {
            int gud = (s1[i - 1] != s2[j - 1]) ? 1 : 0;

            dp[i][j] = gud + dp[i - 1][j - 1];

            if (i >= l && j >= l) {
                int win = dp[i][j] - dp[i - l][j - l];
                if (win <= k)  return 1;
            }
        }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> k >> s1 >> s2;
    n = s1.length();
    dp.resize(n + 1, vi(n + 1, 0));

    int l = 0, r = n, res = 0;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (mid == 0) {
            l = mid + 1;
            continue;
        }

        if (check(mid)) {
            res = mid;
            l = mid + 1;
        } 
        else r = mid - 1;
        
    }
    cout << res;
    return 0;
}
