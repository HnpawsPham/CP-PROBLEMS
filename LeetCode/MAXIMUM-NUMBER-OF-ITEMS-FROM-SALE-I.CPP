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

    int n, k;
    cin>>n>>k;
    vector<vi> a(n, vi(2));
    for(int i = 0; i < n; i++)
        cin>>a[i][0]>>a[i][1];

    const int maxn = 1505;
    int f[maxn];
    memset(f, 0, sizeof f);
    for(const vi& v : a)
        f[v[0]]++;

    int cnt[n];
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < n; i++){
        for(int j = a[i][0]; j < maxn; j += a[i][0])
            cnt[i] += f[j];
        cnt[i]--;
    }

    int dp[k + 1];
    memset(dp, 0, sizeof dp);

    for(int i = 0; i < n; i++){
        for(int j = k; j >= a[i][1]; j--)
            dp[j] = max(dp[j], dp[j - a[i][1]] + cnt[i] + 1);
    }

    for(int i = 0; i < n; i++){
        for(int j = a[i][1]; j <= k; j++)
            dp[j] = max(dp[j], dp[j - a[i][1]] + 1);
    }

    cout<<*max_element(dp, dp + k + 1);
    return 0;
}

// 3 9
// 6 2
// 2 6
// 3 4