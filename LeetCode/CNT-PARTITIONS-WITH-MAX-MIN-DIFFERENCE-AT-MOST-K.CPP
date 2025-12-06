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

const int MOD = 1e9 + 7;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    // int dp[n + 1];
    // dp[0] = 1;

    // int minn, maxx;
    // for(int i = 1; i <= n; i++){
    //     minn = maxx = a[i - 1];

    //     for(int j = i; j > 0; j--){
    //         minn = min(minn, a[j - 1]);
    //         maxx = max(maxx, a[j - 1]);

    //         if(maxx - minn > k) break;
    //         dp[i] = (dp[i] + dp[j - 1]) % MOD;
    //     }
    // }
    // cout<<dp[n];

    int dp[n] = {0}, p[n + 1] = {0};
    deque<int> minn, maxx;
    int pos = 0;
    p[0] = 1;

    for(int i = 0; i < n; i++){
        while(!minn.empty() && a[minn.back()] > a[i]) minn.pop_back();
        minn.push_back(i);

        while(!maxx.empty() && a[maxx.back()] < a[i]) maxx.pop_back();
        maxx.push_back(i);

        while(!minn.empty() && !maxx.empty() && a[maxx.front()] - a[minn.front()] > k){
            if(minn.front() == pos) minn.pop_front();
            if(maxx.front() == pos) maxx.pop_front();
            pos++;
        }

        if(pos == 0) dp[i] = p[i];
        else dp[i] = (p[i] - p[pos - 1] + MOD) % MOD;
        p[i + 1] = (p[i] + dp[i]) % MOD;
    }
    cout<<dp[n - 1];
    return 0;
}

// 5 4
// 9 4 1 3 7

// 3 0
// 3 3 4