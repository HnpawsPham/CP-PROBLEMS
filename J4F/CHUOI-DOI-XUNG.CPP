#include <iostream>
using namespace std;
#define el "\n"

string s, res;
const int maxn = 2005;
int dp[maxn][maxn] = {};

void sol(int i, int j, int l, int r){
    if(l > r) return;
    if(i == j) res[l] = s[i];
    else{
        if(s[i] == s[j]){
            res[l] = res[r] = s[i];
            sol(i + 1, j - 1, l + 1, r - 1);
        }
        else{
            if(dp[i][j] == dp[i + 1][j]) 
                sol(i + 1, j, l, r);
            else sol(i, j - 1, l, r);
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    int n = s.length();

    for(int i = n - 1; i >= 0; i--) // right
        for(int j = 0; j < n; j++){ // left
            if(i == j) dp[i][j] = 1;

            else if(s[i] == s[j])
                dp[i][j] = (i + 1 == j) ? 2 : dp[i + 1][j - 1] + 2;

            else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    
    res.resize(dp[0][n - 1]);
    sol(0, n - 1, 0, dp[0][n - 1] - 1);
    cout<<res;
    return 0;
}