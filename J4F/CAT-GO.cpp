#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>

int n, m;
const int maxx = 50;
int a[55], val[55];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i<=n;i++) cin>>a[i];

    cin>>m;

    for(int i = 0; i< 55; i++) val[i] = 0;

    while(m--){
        int len, x;
        cin>>len>>x;
        val[len] = max(val[len], x);
    }

    vector<vector<int>> dp(n + 1, vector<int>(maxx * maxx + 1, 0));
    vector<vector<int>> p(maxx + 1, vector<int>(maxx + 1, 0));

    for(int i = 1; i<=maxx;i++) p[i][0] = -INT_MAX;

    for(int i = 1; i<=maxx; i++)  //do dai cac thanh go
        for(int j = 1; j <= i; j++) //so lan cat
            for(int prev = 0; prev < i; prev++) //cac do dai truoc do
                p[i][j] = max(p[i][j], p[prev][j - 1] + val[i - prev]);

    
    for(int i = 1; i <= n;i++) //cac tam go hien co
        for(int j = 1; j <= a[i]; j++) // so doan cat toi da
            for(int c = j - 1; c <= maxx * maxx; c++) //so lan cat
                dp[i][c] = max(dp[i][c], dp[i - 1][c - j + 1] + p[a[i]][j]);
            
            
    int res = 0;
    for(int i = 0; i<= maxx * maxx; i++) res = max(res, dp[n][i] - (i * (i + 1)/2));
    cout<<res;

    return 0;
}