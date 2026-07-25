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

int dx[3] = {-1, 0, 1};

bool check(int pos, int m){
    return (pos >= 0 && pos < m);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>a[i][j];

    int dp[n][m][m]; // n, robot1 col, robot2 col
    for(int i = 0; i < n; i++)
        for(int c1 = 0; c1 < m; c1++)
            for(int c2 = 0; c2 < m; c2++)
                dp[i][c1][c2] = -7005;

    dp[0][0][m - 1] = a[0][0] + a[0][m - 1];

    for(int i = 1; i < n; i++)
        for(int c1 = 0; c1 < m; c1++)
            for(int c2 = 0; c2 < m; c2++)
                for(int x1 = 0; x1 < 3; x1++)
                    for(int x2 = 0; x2 < 3; x2++){
                        int pos1 = c1 + dx[x1];
                        int pos2 = c2 + dx[x2];

                        if(!check(pos1, m) || !check(pos2, m))
                            continue;

                        if(c1 != c2) dp[i][c1][c2] = max(dp[i][c1][c2], 
                        dp[i - 1][pos1][pos2] + a[i][c1] + a[i][c2]);

                        else dp[i][c1][c2] = max(dp[i][c1][c2], 
                        dp[i - 1][pos1][pos2] + a[i][c1]); 
                }
    
    int maxx = 0;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            if(i != j) maxx = max(maxx, dp[n - 1][i][j]);
    cout<<maxx;
    return 0;
}

// 4 3
// 3 1 1
// 2 5 1
// 1 5 5
// 2 1 1