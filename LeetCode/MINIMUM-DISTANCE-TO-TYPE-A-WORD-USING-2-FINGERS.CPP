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

int d(int x, int y){
    if(x == 26) return 0;
    int i = x / 6, j = x % 6;
    int i1 = y / 6, j1 = y % 6;
    return abs(i - i1) + abs(j - j1);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    int n = s.length();

    const int oo = 1e6 + 5;
    vector<vi> dp(n, vi(27,oo));
    dp[0][26] = 0;

    for(int i = 0; i < n - 1; i++){
        int cur = s[i] - 'A';
        int next = s[i + 1] - 'A';

        for(int j = 0; j <= 26; j++){
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + d(cur, next));
            dp[i + 1][cur] = min(dp[i + 1][cur], dp[i][j] + d(j, next));
        }
    }
    cout<<*min_element(dp[n - 1].begin(), dp[n - 1].end());
    return 0;
}

// CAKE

// HAPPY