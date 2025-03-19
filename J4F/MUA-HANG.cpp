#include <bits/stdc++.h>
using namespace std;
using ll = int long long;
#define el "\n"
#define INF (ll)1e18

int n, m;
const int maxn = (int)1e5 + 5;
int a[maxn];
ll t[maxn];
vector<vector<int>> pos(maxn);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    
    for(int i = 1; i<=n; ++i) {
        cin>>a[i];
        pos[a[i]].push_back(i);
    }
    
    for(int i = 1; i<=n; ++i) cin>>t[i];

    vector<ll> dp(n + 1, INF);
    ll res = INF;

    for(int i : pos[1]) {
        dp[i] = t[i];
        if(m == 1) res = min(res, dp[i]);
    }
    
    for(int r = 2;r<=m; ++r){
        int j = 0;
        ll nearest = INF;

        for(int i : pos[r]){
            while(j < pos[r - 1].size() && pos[r - 1][j] < i){
                nearest = min(nearest, dp[pos[r - 1][j]] - pos[r - 1][j]);
                j++;
            }
            dp[i]= min(dp[i], t[i] + nearest + i);
        }

        j = pos[r - 1].size() - 1;
        nearest = INF;
        reverse(pos[r].begin(), pos[r].end());

        for(int i : pos[r]){
            while(j >= 0 && pos[r - 1][j] > i){
                nearest = min(nearest, dp[pos[r - 1][j]] + pos[r - 1][j]);
                j--;
            }
            dp[i] = min(dp[i], t[i] + nearest - i);
        }
        reverse(pos[r].begin(), pos[r].end());
    }

    for(int i : pos[m]) res = min(res, dp[i]);
    cout<<res;

    return 0;
}
