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
#define taskname "BALANCE"

int n;
const int maxn = 2e5 + 15;
ll a[maxn];

int main(){
    #ifdef taskname
        freopen("BALANCE.INP", "r", stdin);
        freopen("BALANCE.OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    memset(a, 0, sizeof a);
    ll sum = 0;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        sum += a[i];
    }

    ll p = 0, d = 1e15 + 5;
    for(int i = 0; i < n; i++){
        p += a[i];
        d = min(d, abs(sum - 2LL * p));
    }
    cout<<d;
    return 0;
}