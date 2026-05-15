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

    ll n, k;
    cin>>n>>k;
    if(k / 2 > n) return cout<<0, 0;
    ll res = min(max(0LL, k / 2 - (k % 2 == 0)), min(n, k) - k / 2);
    cout<<res;
    return 0;
}