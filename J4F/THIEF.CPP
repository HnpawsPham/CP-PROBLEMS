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

int n, w, h;
const int maxn = 105;
const int maxv = 1e5 + 5;
const ll oo = 1e13;
int a[maxn], val[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>w>>h;
    for(int i = 0; i < n; i++) cin>>a[i]>>val[i];

    ll dp[maxv][2];
    for(int i = 0; i < maxv; i++) dp[i][0] = dp[i][1] = oo;
    dp[0][0] = 0;

    for(int i = 0; i < n; i++)
        for(int j = maxv - 1; j >= val[i]; j--){
            dp[j][0] = min(dp[j][0], dp[j - val[i]][0] + a[i]);
            dp[j][1] = min(dp[j][1], dp[j - val[i]][1] + a[i]);

            if(a[i] <= h)
                dp[j][1] = min(dp[j][1], dp[j - val[i]][0]);
        }

    for(int i = maxv - 1; i >= 0; i--)
        if(dp[i][0] <= w || dp[i][1] <= w)
            return cout<<i, 0;
    return 0;
}

// 3 10 2
// 2 5
// 1 9
// 4 6

// 3 2 4
// 2 5
// 1 9
// 4 6