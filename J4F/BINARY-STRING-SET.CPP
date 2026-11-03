#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

int tc = 1;

int sol(){
    string s;
    cin>>s;
    int n = s.length();

    int dp[n + 3];
    for(int i = 1; i < n + 3; i++)
        dp[i] = n + 15;

    dp[0] = 0;
    for(int i = 0; i < n; i++){
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        if(s[i] == '0')
            dp[i + 1] = min(dp[i + 1], dp[i]);

        if(i + 1 < n && ((s[i] == '0' && s[i + 1] == '1') || (s[i] == '1' && s[i + 1] == '0')))
            dp[i + 2] = min(dp[i + 2], dp[i]);
    }
    return dp[n];
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}