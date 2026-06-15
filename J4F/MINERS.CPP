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

int mp(char x){
    if(x == 'M') return 1;
    if(x == 'F') return 2;
    return 3;
}

int cost(int prev2, int prev1, int cur){
    int res = 1;
    if(prev1 != 0 && prev1 != cur) res++;
    if(prev2 != 0 && prev2 != cur && prev1 != prev2) res++;
    return res;
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
    string s;
    cin>>n>>s;
    
    int dp[n + 1][4][4][4][4];
    const int oo = 3e5 + 5;
    for(int x = 0; x <= n; x++)  
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                for(int a = 0; a < 4; a++)
                    for(int b = 0; b < 4; b++)
                        dp[x][i][j][a][b] = -oo;
    dp[0][0][0][0][0] = 0;

    for(int i = 1; i <= n; i++){
        for(int prev2 = 0; prev2 < 4; prev2++)
            for(int prev1 = 0; prev1 < 4; prev1++)
                for(int a = 0; a < 4; a++)
                    for(int b = 0; b < 4; b++){
                        int cur = mp(s[i - 1]);
                        int prev = dp[i - 1][prev2][prev1][a][b];
                            
                        // mo 1
                        dp[i][prev1][cur][a][b] = max(
                            dp[i][prev1][cur][a][b],
                            prev + cost(prev2, prev1, cur));

                        // mo 2
                        dp[i][prev2][prev1][b][cur] = max(
                            dp[i][prev2][prev1][b][cur],
                            prev + cost(a, b, cur));
                    }
    }
    
    int res = -oo;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            for(int a = 0; a < 4; a++)
                for(int b = 0; b < 4; b++)
                    res = max(res, dp[n][i][j][a][b]);
    cout<<res;
    return 0;
}