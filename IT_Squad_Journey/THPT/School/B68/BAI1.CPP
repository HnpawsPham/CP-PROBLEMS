#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define fi first
#define se second
#define taskname "BAI1"

int tc;
vector<pll> q;

namespace sub1{
    void sol(){
        for(const auto&[l, r] : q){
            int cnt = 0;
            for(int i = l; i <= r; i++){
                string s = to_string(i);
                int n = s.length();

                bool ok = 1;
                for(int i = 1; i < n && ok; i++)
                    if(s[i] == s[i - 1]) ok = 0;
                cnt += ok;
            }
            cout<<cnt;
        }
    }
}

namespace sub3{
    ll dp[20][2][2][11]; // len, st, less, prev
    string lim;

    ll dfs(int i, bool st, bool less, int prev){
        if(i == lim.size()) return st;

        if(dp[i][st][less][prev + 1] != -1)
            return dp[i][st][less][prev + 1];

        int maxx = 9;
        if(!less) maxx = lim[i] - '0';

        ll res = 0;
        for(int j = 0; j <= maxx; j++){
            if(st && j == prev) continue; 
            
            int prev1 = (st || j > 0) ? j : -1; 
            res += dfs(i + 1, st || j > 0, less || (j < maxx), prev1);
        }
        return dp[i][st][less][prev + 1] = res;
    }

    void sol(){
        for(const auto&[l, r]: q){
            memset(dp, -1, sizeof dp);
            lim = to_string(r);
            ll resr = dfs(0, 0, 0, -1);

            memset(dp, -1, sizeof dp);
            lim = to_string(l - 1);
            ll resl = dfs(0, 0, 0, -1);

            cout<<resr - resl<<el;
        }
    }    
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
    ll maxx = 0;
    for(int i = 0; i < tc; i++){
        ll l, r;
        cin>>l>>r;
        q.push_back({l, r});
        maxx = max(maxx, max(l, r));
    }

    if(tc == 1 && maxx <= 1000000) sub1::sol();
    else sub3::sol();
    return 0;
}