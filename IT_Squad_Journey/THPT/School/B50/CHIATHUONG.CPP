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
// #define taskname "CHIATHUONG"

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
    int a[n + 1] = {0};
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        sum += a[i];
    }

    int m = (n + 1) / 2;
    bool dp[m + 1][sum + 1];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++)
        for(int j = m; j >= 1; j--)
            for(int s = sum; s >= a[i]; s--){
                dp[j][s] |= dp[j - 1][s - a[i]];
            }
    
    int minn = sum * 2;
    int x, y;
    for(int i = 0; i <= sum; i++){
        if(!dp[m][i]) continue;
        int d = abs(2 * i - sum);

        if(d < minn){
            minn = d;
            x = min(i, sum - i);
            y = max(i, sum - i);
        }
    }
    cout<<x<<" "<<y;
    return 0;
}