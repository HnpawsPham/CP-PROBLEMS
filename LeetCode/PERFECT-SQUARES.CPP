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
    vector<int> num;
    for(int i = 1; i <= 1e2; i++)
        num.push_back(i * i);

    vector<int> dp(n + 1, oo);
    dp[0] = 0;

    for(const int& x : num){
        for(int i = x; i <= n; i++){
            dp[i] = min(dp[i], dp[i - x] + 1);
        }
    }
    cout<<dp[n];
    return 0;
}