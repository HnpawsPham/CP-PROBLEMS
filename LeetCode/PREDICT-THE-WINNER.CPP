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

int dp[25][25];

int sol(int l, int r, const vector<int>& a){
    if(l > r) return 0;
    if(l == r) return a[l];
    if(dp[l][r] != -1) return dp[l][r];

    return dp[l][r] = max(a[l] - sol(l + 1, r, a), a[r] - sol(l, r - 1, a));
}

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

    int sum = accumulate(a.begin(), a.end(), 0);
    memset(dp, -1, sizeof dp);
    cout<<(sol(0, a.size() - 1, a) >= 0);
    return 0;
}

// 3
// 1 5 2

// 4
// 1 5 233 7