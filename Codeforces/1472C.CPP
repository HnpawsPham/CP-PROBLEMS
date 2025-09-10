#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc, n;
    cin>>tc;
    while(tc--){
        cin>>n;
        int a[n];
        for(int i = 0; i < n; i++) cin>>a[i];

        ll dp[n] = {0};
        for(int i = n - 1; i >= 0; i--){
            dp[i] = a[i];
            if(i + a[i] < n)
                dp[i] = max(dp[i], dp[i + a[i]] + a[i]);
        }
        cout<<*max_element(dp, dp + n)<<el;
    }

    return 0;
}