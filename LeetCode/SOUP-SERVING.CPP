#include <bits/stdc++.h>
using namespace std;
using db = double;
#define el '\n'
#define vdb vector<db>

vector<vdb> DP;

db dp(int a, int b){
    if(a <= 0 && b <= 0) return 0.5;
    if(a <= 0) return 1.0;
    if(b <= 0) return 0.0;
    return DP[a][b];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    n = (n + 24) / 25;
    if(n >= 4800) return cout<<fixed<<setprecision(5)<<1, 0;

    DP.assign(n + 1, vdb(n  +1, 0));

    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++){
            DP[i][j] = 0.25 * (dp(i - 4, j) + dp(i - 3, j - 1) + dp(i - 2, j - 2) + dp(i - 1, j - 3));
        }
    cout<<fixed<<setprecision(5)<<DP[n][n];
    return 0;
}