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

int q, n;
int comp[11] = {4, 6, 8, 9, 10, 12, 14, 15, 16, 18, 20};
const int maxn = 5e5 + 5;
bitset<maxn> nprime;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
 
    int dp[maxn] = {0};
    for(int i = 4; i < maxn; i++){
        for(const int& x : comp){
            if(i == x) dp[i] = max(dp[i], 1);
            else if(i > x && dp[i - x])
                dp[i] = max(dp[i], dp[i - x] + 1);
        }
    }

    while(q--){
        cin>>n;
        
        if(n < maxn)
            cout<<(dp[n] ? dp[n] : -1)<<el;
        else{
            int d = (n - maxn) / 4 + 1;
            cout<<dp[n - 4 * d] + d<<el;
        }
    }
    return 0;
}

// 20
// 8
// 13
// 20
// 12
// 9
// 16
// 4
// 19
// 7
// 15
// 10
// 6
// 14
// 11
// 3
// 2
// 5
// 17
// 18
// 1