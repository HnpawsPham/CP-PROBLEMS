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

    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n ;i++) cin>>a[i];

    const int oo = 5 * n; 
    vector<int> dp(n, -oo);
    dp[0] = 0;
    for(int i = 1; i < n; i++)
        for(int j = 0; j < i; j++)
            if(abs(a[i] - a[j]) <= k)
                dp[i] = max(dp[i], dp[j] + 1);
    cout<<(dp[n - 1] == -oo ? -1: dp[n - 1]);
    return 0;
}

// 6 2
// 1 3 6 4 1 2

// 6 3
// 1 3 6 4 1 2