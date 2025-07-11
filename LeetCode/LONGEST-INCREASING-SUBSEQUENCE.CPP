#include <bits/stdc++.h>
using namespace std;
#define el '\n'
#define vi vector<int>

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    // vi dp(n, 1);

    // int res = 0;
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < i; j++)
    //         if(a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
        
    //     res = max(res, dp[i]);
    // }
    // cout<<res;

    vi dp;
    dp.push_back(a[0]);

    for(int i = 1; i < n; i++){
        if(a[i] > dp.back())
            dp.push_back(a[i]);

        else if(a[i] < dp.back()){
            auto it = lower_bound(dp.begin(), dp.end(), a[i]);
            
            if(it != dp.end())
                *it = a[i];
        }
    }
    cout<<dp.size();
    return 0;
}

// 8
// 10 9 2 5 3 7 101 18