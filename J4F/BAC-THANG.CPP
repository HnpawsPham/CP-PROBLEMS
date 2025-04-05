#include <iostream>
using namespace std;
#define MOD 14062008

int n, k;

int main(){
    cin>>n>>k;
    bool broken[n + 1] = {};
    while(k--){
        int x; cin>>x;
        broken[x] = 1;
    }

    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++)
        dp[i] = (dp[i - 1] * (!broken[i - 1]) + dp[i - 2] * (!broken[i - 2])) % MOD;
    
    cout<<dp[n];
    return 0;
}