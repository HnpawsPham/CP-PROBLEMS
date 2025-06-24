#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    if(n == 1) return 0;

    // vector<int> dp(n, n + 1);
    // dp[0] = 1;

    // for(int i = 1; i < n; i++)
    //     for(int j = 1; j <= a[i]; j++)
    //         dp[i] = min(dp[i], dp[a[i] - j] + 1);

    // cout<<dp[n - 1];

    int maxx = 0, cnt = 0, en = 0;
    for(int i = 0; i < n - 1; i++){
        maxx = max(maxx, i + a[i]);

        if(i == en){
            cnt++;
            en = maxx;
        }
    }
    cout<<cnt;

    return 0;
}