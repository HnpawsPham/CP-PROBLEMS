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
ll a[maxn], p[maxn] = {0}, s[maxn] = {0}, m;

bool check(ll t){
    ll sum = 0;
    for(int i = 0; i < n; i++)
        sum += max(0LL, min(p[i], s[i + 1]) - max(t, a[i]));
    return sum >= m;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 0; i < n; i++) cin>>a[i];

    for(int i = 1; i <= n; i++)
        p[i] = max(p[i - 1], a[i - 1]);

    for(int i = n - 1; i >= 0; i--)
        s[i] = max(s[i + 1], a[i]);

    ll l = 1, r = 1e18 + 5, mid, res = -1;
    while(l <= r){
        mid = l + (r - l) / 2;
        if(check(mid)){
            l = mid + 1;
            res = mid;
        }
        else r = mid - 1;
    }
    cout<<res;
    return 0;
}

// 7 4
// 4 1 3 2 5 1 6