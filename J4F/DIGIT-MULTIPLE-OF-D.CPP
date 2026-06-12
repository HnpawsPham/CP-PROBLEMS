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

string s;
int n, d;
const ll MOD = 1e9 + 7;
const int maxn = 1e4 + 5;
ll dp[maxn][105][2];

ll dfs(int i, int sum, bool less){
    if(i == n)
        return (sum == 0);

    if(dp[i][sum][less] != -1)
        return dp[i][sum][less];

    int maxx = 9;
    if(!less) maxx = s[i] - '0';

    ll res = 0;
    for(int j = 0; j <= maxx; j++)
        res = (res + dfs(i + 1, (sum + j) % d, less || j < maxx)) % MOD;

    return dp[i][sum][less] = res; 
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>s>>d;
    n = s.length();
    memset(dp, -1, sizeof dp);

    cout<<(dfs(0, 0, 0) - 1 + MOD) % MOD;
    return 0;
}