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

const ll oo = 1e16 + 5;
bool comp(const vi& a, const vi& b){
    if(a[1] != b[1]) return a[1] < b[1];
    return a[0] < b[0];
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<vi> a(n, vi(3));
    for(int i = 0; i < n; i++)
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    
    for(int i = 0; i < n; i++)
        a[i].push_back(i);

    sort(a.begin(), a.end(), comp);
    int r[n];
    for(int i = 0; i < n; i++)
        r[i] = a[i][1];

    // w  & indexes
    pair<ll, vi> dp[n + 1][5], res = {0, {}};
    for(int i = 0; i <= n; i++)
        for(int j = 0; j < 5; j++)
            dp[i][j] = {-oo, {}};

    dp[0][0] = {0, {}};
    for(int i = 1; i <= n; i++){
        int prev = lower_bound(r, r + i - 1, a[i - 1][0]) - r;

        for(int j = 0; j < 5; j++){
            dp[i][j] = dp[i - 1][j];
            if(j == 0 || dp[prev][j - 1].fi == -oo) continue;

            auto [w, id] = dp[prev][j - 1];
            w += a[i - 1][2];
            id.push_back(a[i - 1][3]);
            sort(id.begin(), id.end());

            if(w > dp[i][j].fi || (w == dp[i][j].fi && id < dp[i][j].se))
                dp[i][j] = {w, id};
        }
    }

    for(int i = 0; i <= n; i++)
        for(int j = 0; j < 5; j++)
            if(res.fi < dp[i][j].fi || (res.fi == dp[i][j].fi && dp[i][j].se < res.se))
                res = dp[i][j];

    for(const int& x : res.se)
        cout<<x<<" ";
    return 0;
}

// 6
// 1 3 2
// 4 5 2
// 1 5 5
// 6 9 3
// 6 7 1
// 8 9 1