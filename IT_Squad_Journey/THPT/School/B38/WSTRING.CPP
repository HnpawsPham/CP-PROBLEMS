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
string s;
const int maxn = 205;
string dp[maxn][maxn];

string sol(int i, int j){
    if(dp[i][j] != "") return dp[i][j];
    int m = j - i + 1;
    string res = s.substr(i, m);

    if(m < 4) return dp[i][j] = res;

    int p = (res + res).find(res, 1);
    if(p < m){
        string ss = to_string(m / p) + '(' + sol(i, i + p - 1) + ')';

        if(ss.size() < m || (ss.size() == m && ss < res)) 
            res = ss;
    }

    for (int mid = i; mid < j; mid++) {
        string tmp = sol(i, mid) + sol(mid + 1, j);
        
        if (tmp.size() < res.size() || (tmp.size() == res.size() && tmp < res)) 
            res = tmp;
    }
    return dp[i][j] = res;
}

int main(){
    freopen("WSTRING.INP", "r", stdin);
    // freopen("WSTRING.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    // tc = 1;
    while(tc--){
        cin>>n>>s;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) dp[i][j] = "";

        cout<<sol(0, n - 1)<<el;
    }
    return 0;
}