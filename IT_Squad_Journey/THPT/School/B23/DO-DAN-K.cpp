#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, k;
const int maxn = (int)1e6 + 5;
const ll MOD = (ll)1e9 + 7;
int a[maxn];
int p[maxn];

int main(){
    freopen(".\\txt\\DO-DAN-K.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    ll s;

    for(int i = 1; i <= n; i++){
        cin>>a[i];
        s += a[i];
        p[i] = p[i - 1] + a[i];
    }
    
    int dp[n + 1];

    

    cout<<s % MOD;
    return 0;
}