#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int n, k;

bool comp(vi& a, vi& b){
    return a[1] < b[1];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    vector<vi> a(n);
    for(int i = 0; i < n; i++){
        int x, y, z;
        cin>>x>>y>>z;
        a[i] = {x, y, z};
    }

    sort(a.begin(), a.end(), comp);
    vi prev(n, -1);

    for(int i = 0; i < n; i++)
        for(int j = i - 1; j >= 0; j--)
            if(a[j][1] < a[i][0]) {
                prev[i] = j + 1;
                break;
            }

    vector<vi> dp(n + 1, vi(k + 1, 0));
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++){
            dp[i][j] = dp[i - 1][j];

            if(prev[i - 1] != -1)
                dp[i][j] = max(dp[i][j], dp[prev[i - 1]][j - 1] + a[i - 1][2]);

            else dp[i][j] = max(dp[i][j], a[i - 1][2]);
        }
    }

    int res = 0;
    for(int i = 1; i <= n; i++)
        res = max(res, dp[i][k]);
        
    cout<<res;
    return 0;
}
// 3 2
// 1 2 4
// 3 4 3
// 2 3 1
