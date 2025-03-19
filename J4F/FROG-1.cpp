#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define el "\n"

int n;
const int maxn = 2* (int)1e5 + 5;
const ll INF = 1e9 + 5;
int a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i<=n; ++i) cin>>a[i];

    vector<ll> dp(n + 1, INF);
    dp[1] = 0;

    for(int i = 2; i <= n; ++i){
        dp[i] = min(dp[i], dp[i - 1] + abs(a[i - 1] - a[i]));
        if(i > 2) dp[i] = min(dp[i], dp[i - 2] + abs(a[i - 2] - a[i]));
    }
    cout<<dp[n];
    return 0;
}