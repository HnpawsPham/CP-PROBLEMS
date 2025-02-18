#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
const int maxn = 30005;
int a[maxn];

void sol_slow(){
    int dp[n + 1];
    int res = 0;

    for(int i = 1; i<=n;i++){
        dp[i] = 1;
        for(int j = 1; j<i;j++)
            if(a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
        res = max(res, dp[i]);
    }
    cout<<res;
    return;
}

void sol_fast(){
    vector<int> dp;
    for(int i = 1; i<=n;i++){
        int pos = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
        if(pos == dp.size()) dp.push_back(a[i]);
        else dp[pos] = a[i];
    }
    cout<<dp.size();
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i<= n; i++) cin>>a[i];
    // sol_fast();
    sol_slow();

    return 0;
}