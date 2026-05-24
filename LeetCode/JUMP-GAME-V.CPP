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
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<pii> p;
    for(int i = 0; i < n; i++)
        p.push_back({a[i], i});
    sort(p.begin(), p.end());

    vector<int> dp(n, 1);
    for(int it = 0; it < n; it++){
        int i = p[it].se;
        for(int j = 1; j <= k; j++)
            if(i + j < n){
                if(a[i] > a[i + j]) dp[i] = max(dp[i + j] + 1, dp[i]);
                else break;
            }

        for(int j = 1; j <= k; j++)
            if(i - j >= 0){
                if(a[i] > a[i - j]) dp[i] = max(dp[i - j] + 1, dp[i]);
                else break;
            }
    }
    cout<<*max_element(dp.begin(), dp.end());
    return 0;
}

// 11 2
// 6 4 14 6 8 13 9 7 10 6 12

// 5 3
// 3 3 3 3 3

// 7 1
// 7 6 5 4 3 2 1