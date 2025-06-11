#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;

void sub1(){
    vector<bool> dp(n, 0);
        dp[0] = 1;

        for(int i = 0; i < n; i++){
            if(dp[i])
                for(int j = 1; j <= a[i] && i + j < n; j++)
                    dp[i + j] = 1;
        }
    cout<<dp[n - 1];
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    int maxx = 0;
    for(int i = 0; i < n; i++){
        if(maxx < i) return cout<<0, 0;
        maxx = max(maxx, a[i]);
    }
    return 0;
}