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

const int maxn = 15005;
const int oo = 1e9 + 15;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin>>n>>s;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);

    int d = 0;
    if(s >= maxn){
        d = (s - 15000) / a[n - 1];
        s -= d * a[n - 1];
    }

    int dp[2 * maxn] = {0};
    for(int w = 1; w <= s; w++){
        dp[w] = oo;
        for(int i = 0; i < n && a[i] <= w; i++)
            dp[w] = min(dp[w], dp[w - a[i]] + 1);
    }
    cout<<dp[s] + d;
    return 0;
}