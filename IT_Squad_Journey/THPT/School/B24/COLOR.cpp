#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define MOD 1000000007

const int maxn = 2 * (int)1e6 + 5;
int a[maxn];
int n, l, r;

bool check(int st, int en){
    unordered_set<int> s;
    for(int i = st; i < en;i++) 
        s.insert(a[i]);
    return l <= s.size() && s.size() <= r;
}

int main(){
    freopen(".\\txt\\COLOR.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>l>>r;
    for(int i = 0; i< n; ++i) cin>>a[i];

    ll dp[n + 1];
    memset(dp, 0 , sizeof(dp));
    dp[0] = 1;

    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < i; ++j){
            if(check(j, i)) 
                dp[i] = (dp[i] + dp[j]) % MOD;
        }
    }
    cout<<dp[n];
    
    return 0;
}