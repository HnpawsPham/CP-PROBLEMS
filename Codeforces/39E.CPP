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

int a, b;
ll n;
const int maxn = 1e5 + 5;
ll dp[maxn][55];

int sol(int i, int j){
    if(dp[i][j] != -1) return dp[i][j];
    
    if(pow(i, j) >= n) return dp[i][j] = 0;
    return dp[i][j] = !(sol(i + 1, j) || sol(i, j + 1));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>b>>n;
    memset(dp, -1, sizeof dp);
    if(a == 1 && (ll)pow(a + 1, b) >= n) return cout<<"Missing", 0;

    // for(int i = maxn - 1; i >= a; i--)
    //     for(int j = 34; j >= b; j--){
    //         if((ll)pow(i, j) >= n) dp[i][j] = 0;
    //         else dp[i][j] = !(dp[i + 1][j] || dp[i][j + 1]);
    //     }

    // cout<<(dp[a][b] ? "Stas" : "Masha");
    cout<<(sol(a, b) ? "Stas" : "Masha");
    return 0;
}

// 10000 1 1000000000