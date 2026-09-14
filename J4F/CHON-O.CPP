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

int n;
const int maxn = 1e4 + 5;
const int maxsz = (1 << 4);
const int oo = 1e9 + 15;
int a[4][maxn], dp[maxn][maxsz];

bool check(int mask){
    for(int i = 0; i < 3; i++)
        if((mask & (1 << i)) && (mask & (1 << (i + 1))))
            return 0;
    return 1;
}

int calc(int mask, int j){
    int res= 0;
    for(int i = 0; i < 4; i++)
        if(mask & (1 << i)) 
            res += a[i][j];
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
    
    cin>>n;
    for(int i = 0; i < 4; i++)
        for(int j = 1; j <= n; j++)
            cin>>a[i][j];

    for(int i= 0; i <= n; i++)
        for(int j = 0; j < maxsz; j++)
            dp[i][j] = -oo;

    dp[0][0] = 0;
    int res = -oo;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < maxsz; j++){
            if(!check(j)) continue;
            int sum = calc(j, i);

            for(int x = 0; x < maxsz; x++){
                if(!check(x) || (j & x)) continue;
                dp[i][j] = max(dp[i][j], dp[i - 1][x] + sum);
                if(j > 0) res = max(res, dp[i][j]);
            }
        }
    cout<<res;
    return 0;
}