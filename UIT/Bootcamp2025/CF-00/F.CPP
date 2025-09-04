#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int calc(char open, char close) {
    if(open == '?' && close == '?') return 3;
    if(open == '?') {
        if(close == ')' || close == ']' || close == '}') return 1;
        return 0;
    }
    if(close == '?') {
        if(open == '(' || open == '[' || open == '{') return 1;
        return 0;
    }
    if(open == '(' && close == ')') return 1;
    if(open == '[' && close == ']') return 1;
    if(open == '{' && close == '}') return 1;
    return 0;
}

const int MOD = 1e5;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin>>n>>s;
    s = '-' + s;

    __int128 dp[n + 1][n + 1]; 
    bool add0 = 0;

    for(int len = 2; len <= n; len++) {
        if(len % 2) continue;
        for(int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            __int128 res = 0;

            for(int k = l + 1; k <= r; k += 2) {
                int cnt = calc(s[l], s[k]);
                if(cnt == 0) continue;
                __int128 left  = (l + 1 <= k - 1 ? dp[l + 1][k - 1] : 1);
                __int128 right = (k + 1 <= r ? dp[k + 1][r] : 1);

                res += (__int128)cnt * left * right;
                if(res > (__int128)1e18) res %= MOD * 10; 
            }
            dp[l][r] = res;
        }
    }

    __int128 res = dp[1][n];
    if(res >= MOD)
        cout<<setw(5)<<setfill('0')<<(ll)(res % MOD);
    else cout<<(ll)res;
    return 0;
}

// 182
// ?[{}??[?{((??)[{{[[?????]?{?[[(([???]{?[????[[?]?({}(()[[?????}(?????{{?((?)))()})]((((??)???(??????((?????)?)??()(?)?((????)?)?((?(????)?)????)]]??]?]))??]????????]?]]????}?)????]??

// 184
// ({}{([[(?((()?(((()([?)[?[(?[??????)][][[??(([(?[]])]?()?][[?([?[]()?(()?))?[[[?(())]?[[?(?(()?](?[[?[[[(?()??[?[]]?[()[(())[?]]?]])]]?]?(((?)???)))?)))]]???]))?])))?]]?)??]))))??]])?)

// 30
// (?[[]??]??)?()?(?[?[?]?)??]???

// 40
// [(?(?(?{{??}(())(???(?}())?()?((???)?)?]