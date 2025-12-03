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
const int maxn = 5e5 + 5;
const ll oo = 1e12 + 5;
int t[maxn], w[maxn];
ll bit[maxn];

void update(int i, ll val){
    while(i <= n){
        bit[i] = min(bit[i], val);
        i += (i & -i);
    }
    return;
}

ll get(int i){
    ll res = oo;
    while(i > 0){
        res = min(res, bit[i]);
        i -= (i & -i);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i <= n; i++) cin>>t[i]>>w[i];

    ll dp[n + 1];
    for(int i = 0; i <= n; i++) bit[i] = oo;
    update(n + 1, 0);

    for(int i = n; i > 0; i--){
        dp[i] = w[i] + get(t[i] + 1);
        update(i, dp[i]);
    }
    cout<<dp[1];
    return 0;
}