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

int tc;
unordered_map<ll, ll> memo, check;

ll dp(ll x){
    if(x <= 0) return 0;
    
    if(memo.count(x)) return memo[x];
    
    ll p = 1;
    while(p * 2 <= x) p *= 2;
    return memo[x] = dp(p - 1) + dp(x - p) + p;
}

ll sol(int n){
    if(n <= 1) return 0;
    
    if(check.count(n)) return check[n];
    
    ll p = 1;
    while(p * 2 <= n) p *= 2;
    
    if(n == p) return check[n] = sol(p - 1) + p + 1;
    return check[n] = sol(p - 1) + dp(n - p) + p;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
	cin>>tc;
	while(tc--){
	    int n;
	    cin>>n;
        cout<<sol(n)<<el;
	}
    return 0;
}
