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
#define taskname "CATDAYSO"

int n;
const int maxn = 2005;
int dp[maxn][maxn], maxx[maxn][maxn];
string s;

bool _greater(int i, int j, int l, int r){
    while(i < j && s[i] == '0') i++;
    while(l < r && s[l] == '0') l++;

    if(j - i != r - l)
        return j - i > r - l;

    while(i <= j && l <= r)
        if(s[i++] < s[l++]) return 0;
    return 1;
}

namespace sub1{
    bool checksub(){
        for(const char& x : s)
            if(x != '0' && x != '1') return 0;
        return 1;
    }
    
    void sol(){
        int cnt0[n + 1], cnt1[n + 1];
        cnt0[0] = cnt1[0] = 0;

        for(int i = 1; i <= n; i++){
            cnt0[i] = cnt0[i - 1] + (s[i - 1] == '0');
            cnt1[i] = cnt1[i - 1] + (s[i - 1] == '1');
        }

        int res = 0;
        for(int i = 1; i <= n; i++)
            res = max(res, cnt0[i] + cnt1[n] - cnt1[i]);
        cout<<res;
    }
}

namespace sub2{
    void sol(){
        int res = 0, sz = (1 << (n - 1));

        for(int i= 0; i < sz; i++){
            vector<pii> a;
            int prev = 0;
            
            for(int j = 0; j < n - 1; j++){
                if(1 & (i >> j)){
                    a.push_back({prev, j});
                    prev = j + 1;
                }
            }
            a.push_back({prev, n - 1});

            int m = a.size();
            int dp[m];
            for(int j = 0; j < m; j++)
                dp[j] = 1;

            for(int j = 1; j < m; j++)
                for(int k = 0; k < j; k++)
                    if(!_greater(a[k].fi, a[k].se, a[j].fi, a[j].se))
                        dp[j] = max(dp[j], dp[k] + 1);

            res = max(res, *max_element(dp, dp + m));
        }
        cout<<res;
    }
}

namespace sub3{
    void sol(){
        memset(dp, 0, sizeof dp);

        int res = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= i; j++){
                dp[i][j] = 1;
                int left = i - j;

                for(int x = 1; x <= left; x++){
                    if(_greater(i - j, i - 1, left - x, left - 1))
                        dp[i][j] = max(dp[i][j], dp[left][x] + 1);
                }
                res = max(res, dp[i][j]);
            }
        cout<<res;
    }
}

namespace sub4{
    void sol(){
        memset(dp, 0, sizeof dp);
        memset(maxx, 0, sizeof maxx);

        int res = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= i; j++){
                dp[i][j] = 1;
                int left = i - j;

                if(left > 0){
                    dp[i][j] = max(dp[i][j], maxx[left][j - 1] + 1);

                    if(left >= j && _greater(i - j, i - 1, left - j, left - 1))
                        dp[i][j] = max(dp[i][j], dp[left][j] + 1);
                }
                
                maxx[i][j] = max(dp[i][j], maxx[i][j - 1]);
                res = max(res, dp[i][j]);
            }
        cout<<res;
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

    cin>>n>>s;

    if(sub1::checksub()) sub1::sol();
    // else if(n <= 24) sub2::sol();
    else if(n <= 200) sub3::sol();
    else sub4::sol();
    return 0;
}

// 8
// 13220131