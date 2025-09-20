#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define vs vector<string> 
#define mask(i, j) ((i >> j) & 1)
#define fi first
#define se second

int tc;
int n, m;

int sum(const vs& a, int cur, int i){
    int cnt = 0;
    for(int j = 0; j < m; j++){
        bool x = mask(cur, j);
        if(x && a[i][j] == '.') cnt++;
        if(!x && a[i][j] == '#') cnt++;
    }
    return cnt;
}

bool check(int i, int x){
    for(int j = 0; j < m - 1; j++)
        if(mask(i, j) && mask(i, j + 1) && mask(x, j) && mask(x, j + 1)) 
            return 0;
    return 1;
}

int sol(){
    vs a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int sz = 1 << m;
    vector<map<int, int>> dp(n);

    for(int i = 0; i < sz; i++)
        dp[0][i] = sum(a, i, 0);

    for(int i = 1; i < n; i++)
        for(int j = 0; j < sz; j++){
            int s = sum(a, j, i);
            for(auto& [prev, x] : dp[i - 1]){
                if(!check(prev, j)) continue;
                if(!dp[i].count(j)) dp[i][j] = x + s;
                else dp[i][j] = min(dp[i][j], x + s);
            }
        }

    int res = INT_MAX;
    for(auto [_, x] : dp[n - 1]) 
        res = min(res, x);
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cin>>n>>m;
        cout<<sol()<<el;
    }
    return 0;
}