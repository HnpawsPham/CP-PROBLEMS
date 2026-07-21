#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define vs vector<string>
#define fi first
#define se second
#define taskname "NX"

int n, k;
const int maxn = 4005;
string a[maxn];

vs prepSub(string s){
    int len = s.length();

    vector<vs> dp(len + 1, vs(k + 1, "{")); 
    for(int i = 0; i <= len; i++) 
        dp[i][0] = "";

    for(int i = 1; i <= len; i++) 
        for(int j = 1; j <= min(k, i); j++) 
            if(dp[i - 1][j - 1] != "{") 
                dp[i][j] = dp[i - 1][j - 1] + s[i - 1];
        
    vs res(k + 1, "{"); 
    for(int i = 1; i <= k; i++) 
        for(int j = 1; j <= len; j++) 
            res[i] = min(res[i], dp[j][i]);
    return res;
}

namespace sub1 {
    void sol() {
        vs sub1 = prepSub(a[0]);
        vs sub2 = prepSub(a[1]);

        string res = "{";
        for(int i = 1; i < k; i++) 
            res = min(res, sub1[i] + sub2[k - i]);
        cout<<res;
    }
}

namespace sub2{
    vs minn[maxn];
    string res = "{";

    void backtrack(int i, int left, string s){
        if(s > res) return;
        if(left < n - i) return;

        if(i == n){
            if(left == 0 && res > s)
                res = s;
            return;
        }

        for(int j = 1; j <= min((int)a[i].length(), left - n + i); j++)
            backtrack(i + 1, left - j, s + minn[i][j]);
        return;
    }

    void sol(){
        for(int i = 0; i < n; i++)
            minn[i] = prepSub(a[i]);

        backtrack(0, k, "");
        cout<<res;
        return;        
    }
}

int main() {
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>a[i];

    if(n == 2) sub1::sol();
    else sub2::sol();
    return 0;
}