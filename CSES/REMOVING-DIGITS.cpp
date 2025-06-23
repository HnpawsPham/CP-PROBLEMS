#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
const int oo = 1e6;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vector<int> dp(n + 1, oo);
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        int x = i;
        while(x > 0){
            dp[i] = min(dp[i], dp[i - (x % 10)] + 1);
            x /= 10;
        }
    }
    cout<<dp[n];
    return 0;
}