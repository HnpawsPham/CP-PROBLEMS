#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define psi pair<string, int>
#define se second

int n, k;
const ll MOD = (ll)1e9 + 7;
const int maxn = 1005;

string a[maxn];
map<string, int> f;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        sort(a[i].begin(), a[i].end());
        f[a[i]]++;
    } 

    vector<int> cnt;
    for(psi x : f) cnt.push_back(x.se);
    int m = cnt.size();

    vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));
    dp[0][0] = 1;

    for(int i = 1; i <= m; i++){
        for(int j = 0; j<=k; j++){
            int s = cnt[i - 1] * (cnt[i - 1] - 1) /2;

            dp[i][j] = dp[i - 1][j];
            if(k >= s) dp[i][j] += dp[i][k - s];
            else dp[i][j]++;
        }
    }
    cout<<dp[m][k];

    return 0;
}