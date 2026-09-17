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

int n, k;
const int maxn = 1e5 + 5;
const int maxk = 105;
const ll oo = 1e16 + 5;
int a[maxn];
ll dp[maxn][maxk], maxx[maxn][maxk];
int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i = 1; i <= n; i++) cin>>a[i];

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= k; j++)
            dp[i][j] = maxx[i][j] = -oo;

    dp[0][0] = 0;
    maxx[0][0] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= k; j++){
            dp[i][j] = dp[i - 1][j];
            if(j > 0)
                dp[i][j] = max(dp[i][j] + a[i], maxx[i - 1][j - 1] + a[i]);

            maxx[i][j] = max(maxx[i - 1][j], dp[i][j]);
        }
    cout<<maxx[n][k];
    return 0;
}