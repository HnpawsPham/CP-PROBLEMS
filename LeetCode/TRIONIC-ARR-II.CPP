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

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    const ll oo = 2e14 + 5;
    vector<vll> dp(4, vll(n, -oo));
    for(int i = 0; i < n; i++) 
        dp[0][i] = a[i];

    for(int i = 1; i < n; i++){
        if(a[i] > a[i - 1]){
            dp[1][i] = max(dp[1][i - 1] + a[i], dp[0][i - 1] + a[i]);
            dp[3][i]= max(dp[2][i - 1] + a[i], dp[3][i - 1] + a[i]);
        }

        if(a[i] < a[i - 1]) 
            dp[2][i] = max(dp[2][i - 1] + a[i], dp[1][i - 1] + a[i]);
    }
    cout<<*max_element(dp[3].begin(), dp[3].end());
    return 0;
}

// 7
// 0 -2 -1 -3 0 2 -1