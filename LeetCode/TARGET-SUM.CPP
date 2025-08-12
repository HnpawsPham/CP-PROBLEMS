#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, target, cnt = 0;
const int maxn = 1000;

void sol(int i, int sum, const vi& a){
    if(i == n){
        if(sum == target) cnt++;
        return; 
    }

    sol(i + 1, sum - a[i], a);
    sol(i + 1, sum + a[i], a);

    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>target;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    // backtracking sol;
    sol(0, 0, a);
    cout<<cnt<<el;

    // dp sol
    int sum = accumulate(a.begin(), a.end(), 0);
    if((target + sum) % 2 || abs(target) > sum) return 0;

    int m = (sum + target) / 2; 
    vi dp(m + 1, 0);
    dp[0] = 1;

    for(int i = 0; i < n; i++)
        for(int j = m; j >= a[i]; j--)
            dp[j] += dp[j - a[i]];
    cout<<dp[m];
    return 0;
}