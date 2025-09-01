#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int a[n + 1][3];
    for(int i = 1; i <= n; i++)
        cin>>a[i][0]>>a[i][1]>>a[i][2];

    int dp[n + 1][3];
    for(int i = 0; i <= n; i++) 
        dp[i][0] = dp[i][1] = dp[i][2] = 0;

    for(int i = 1; i <= n; i++) 
        for(int j = 0; j < 3; j++){
            dp[i][j] = dp[i - 1][j];
            for(int c = 0; c < 3; c++){
                if(c == j) continue;
                dp[i][j] = max(dp[i][j], dp[i - 1][c] + a[i][j]);
            }
        }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 0; j < 3; j++) cout<<dp[i][j]<<" ";
    //     cout<<el;
    // }
    cout<<*max_element(dp[n], dp[n] + 3);
    return 0;
}