#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    
    int res = 0;
    vector<vector<int>> dp(n, vector<int>(k * 2 + 1, 1));
    vector<int> last(k, -1);
    
    for(int i = 0; i < n; i++){
        int cur = a[i] % k;

        for(int prev = 0; prev < k; prev++){
            int d = cur + prev;
            if(last[prev] != -1) 
                dp[i][d] = max(dp[last[prev]][d] + 1, dp[i][d]);

            res = max(res, dp[i][d]);
        }
        last[cur] = i;
    }
    cout<<res;
    return 0;
}
