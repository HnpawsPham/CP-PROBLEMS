#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>

int main(){
    freopen("CARDS.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    string a, b;
    cin>>n>>m>>a>>b;

    vector<vector<vi>> dp(n, vector<vi>(26, vi(m + 1, 0)));

    for(int i = 0; i < n; i++){
        for(int ch = 0; ch < 26; ch++){
            for(int j = 0; j <= m; j++){
                if(i == 0){
                    if(a[0] - 'a' == ch) dp[0][ch][j] = 1;
                    if(j > 0 && b[0] - 'a' == ch) dp[0][ch][j] = 1;
                    continue;
                }

                if(a[i] - 'a' == ch) 
                    dp[i][ch][j] = dp[i - 1][ch][j] + 1;

                else if(j > 0 && b[i] - 'a' == ch) 
                    dp[i][ch][j] = dp[i - 1][ch][j - 1] + 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int ch = 0; ch < 26; ch++){
            for(int j = 0; j <= m; j++){
                if(dp[i][ch][j] > 0){
                    int len = dp[i][ch][j];
                    int start = i - len + 1;
                    char c = 'a' + ch;
                    cout << "From " << start << " to " << i << " = ";
                    cout << string(len, c) << " (flip = " << j << ")" << el;
                }
            }
        }
    }

    return 0;
}