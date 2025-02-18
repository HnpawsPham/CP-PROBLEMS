#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;
const int maxn = 3 * (int)1e5 + 5;
ll a[maxn];
ll p[maxn];

int main(){
    freopen(".\\txt\\MUSIC.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    p[0] = 0;

    for(int i = 1; i <= n; i++){
        cin>>a[i];
        p[i] = p[i - 1] + a[i];
    }

    ll res = -LLONG_MAX;
    
    deque<ll> dp[2];

    for(int i = 1;i<=n;i++){
        int j = (i % 2) ? 1 : 0;
        
        if(!dp[j].empty()){
            res = max(res, p[i] - p[dp[j].front()]);
        }

        while(!dp[j].empty() && p[dp[j].back()] >= p[i]) dp[j].pop_back();

        dp[j].push_back(i);
    }

    cout<<res;
    return 0;
}