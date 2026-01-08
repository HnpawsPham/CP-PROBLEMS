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

    int n, m;
    cin>>n>>m;
    int a[n], b[m];
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>b[i];

    const int oo = 5e5 + 15;
    vector<vi> dp(n + 1, vi(m + 1, -oo));

    for(int i = 0; i <= n; i++) dp[i][0] = 0;
    for(int i = 1; i <= m; i++) dp[0][i] = 0;

    bool ok = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); 
            int tmp = dp[i - 1][j - 1] + a[i - 1] * b[j - 1];
            if(tmp > dp[i][j]){
                ok = 1;
                dp[i][j] = tmp;
            }
        }

    if(!ok){
        int max1 = *max_element(a.begin(), a.end()), max2 = *max_element(b.begin(), b.end());
        int min1 = *min_element(a.begin(), a.end()), min2 = *min_element(b.begin(), b.end());
        cout<<max(max1 * min2, max2 * min1);
    }
    else cout<<dp[n][m];
    return 0;
}

// 4 3
// 2 1 -2 5
// 3 0 -6

// 2 3
// 3 -2
// 2 -6 7