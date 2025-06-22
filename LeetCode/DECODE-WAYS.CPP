#include <bits/stdc++.h>
using namespace std;
#define el "\n"

string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    if(s[0] == '0') return cout<<0, 0;

    int n = s.length();

    int dp[n] = {0};
    dp[0] = 1;

    for(int i = 1; i < n; i++){
        dp[i] += (s[i] != '0');

        int num = (s[i - 1] - '0') * 10 + (s[i] - '0');
        if(10 <= num && num <= 26) dp[i] += dp[i - 1];
    }
    cout<<dp[n - 1];
    return 0;
}