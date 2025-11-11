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

int n;
const int maxn = 1e5 + 5;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int a[n];
    for(int i = 0; i < n; i++) cin>>a[i];

    bool check[maxn] = {0};
    int dp[n + 1] = {0};

    for(int i = n - 1; i >= 0; i--){
        if(check[a[i]]) dp[i] = dp[i + 1];
        else{
            check[a[i]] = 1;
            dp[i] = dp[i + 1] + 1;
        }
    }

    ll res = 0;
    memset(check, 0, sizeof check);
    for(int i = 0; i < n; i++)
        if(!check[a[i]]){
            check[a[i]] = 1;
            res += dp[i + 1];
        }
    cout<<res;
    return 0;
}