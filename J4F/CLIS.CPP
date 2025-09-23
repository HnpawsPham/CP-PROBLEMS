#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n = s.length();
    int dp[n] = {1};

    for(int i = 1; i < n; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++)
            if(s[j] <= s[i]) dp[i] = max(dp[i], dp[j] + 1);
    }
    cout<<*max_element(dp, dp + n);
    return 0;
}