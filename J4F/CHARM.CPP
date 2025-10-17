#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int w[n + 1], v[n + 1];
    for(int i = 1; i <= n; i++) cin>>w[i]>>v[i];

    ll dp[m + 1] = {0};
    for(int i = 1; i <= n; i++)
        for(int j = m; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    cout<<*max_element(dp + 1, dp + m + 1);
    return 0;
}

// 4 6
// 1 4
// 2 6
// 3 12
// 2 7