#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, h, l, r;
const int oo = 1e9;

bool gud(int x){
    return l <= x && x <= r;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>h>>l>>r;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    vector<vi> dp(n + 1, vi(h, -oo));
    dp[0][0] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = h - 1; j >= 0; j--)
            dp[i][j] = max(dp[i - 1][(j - a[i] + h) % h], dp[i - 1][(j - a[i] + 1 + h) % h]) + gud(j);

    cout<<*max_element(dp[n].begin(), dp[n].end());
    return 0;
}