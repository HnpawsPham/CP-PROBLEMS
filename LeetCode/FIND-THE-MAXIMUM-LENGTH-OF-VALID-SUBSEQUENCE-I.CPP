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
    vector<vector<int>> dp(n, vector<int>(3, 1));
    vector<int> last(2, -1);
    
    for(int i = 0; i < n; i++){
        int k = a[i] % 2;

        for(int prev = 0; prev < 2; prev++){
            int d = k + prev;
            if(last[prev] != -1) 
                dp[i][d] = max(dp[last[prev]][d] + 1, dp[i][d]);

            res = max(res, dp[i][d]);
        }
        last[k] = i;
    }
    cout<<res;
    return 0;
}

// 5
// 1 5 9 4 2