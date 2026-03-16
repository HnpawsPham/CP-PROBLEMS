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
#define taskname "chiadat"

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n + 1][n + 1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) cin>>a[i][j];

    int p[n + 1][n + 1];
    memset(p, 0, sizeof p);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + a[i][j];

    int minn = 5005;
    for(int i = 1; i < n; i++)
        for(int j = 1; j < n; j++){
            int sum1 = p[i][j];
            int sum2 = p[i][n] - p[i][j];
            int sum3 = p[n][j] - p[i][j];
            int sum4 = p[n][n] - p[i][n] - p[n][j] + p[i][j];

            minn = min(minn, max({sum1, sum2, sum3, sum4}) - min({sum1, sum2, sum3, sum4}));
        }
    cout<<minn;
    return 0;
}