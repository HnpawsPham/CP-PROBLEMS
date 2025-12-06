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

int n, l;
const int oo = 1e7 + 5;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>l;
    int a[n + 1] = {0};
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        a[i] += a[i - 1];
    }

    int dp[n + 1] = {0};
    for(int i = 1; i <= n; i++){
        dp[i] = oo;
        for(int j = i - 1; j >= 0; j--){
            if(a[i] - a[j] > l) break;
            dp[i] = min(dp[i], max(dp[j], l - a[i] + a[j]));
        }
    }
    cout<<dp[n];
    return 0;
}