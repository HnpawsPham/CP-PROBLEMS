#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc, n;
const int maxn = 205;

string convert(__int128 x){
    if(x == 0) return "0";

    string s;
    while(x > 0){
        s += '0' + (x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;

    __int128 dp[maxn] = {0};
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i < maxn; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    while(tc--){
        cin>>n;
        cout<<convert(dp[n])<<el;
    }

    return 0;
}