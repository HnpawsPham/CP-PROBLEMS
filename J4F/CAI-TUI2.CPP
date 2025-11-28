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

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int dp[m + 1] = {0};

    while(n--){
        int w, v, a, k = 1;
        cin>>w>>v>>a;

        while(a > 0){
            int cnt = min(a, k);
            int w1 = w * cnt, v1 = v * cnt;

            for(int i = m; i >= w1; i--)
                dp[i] = max(dp[i], dp[i - w1] + v1);

            a -= cnt;
            k *= 2;
        }
    }
    cout<<dp[m];
    return 0;
}