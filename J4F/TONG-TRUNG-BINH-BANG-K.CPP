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
    int a[n + 1];
    for(int i = 1; i <=n ;i++) cin>>a[i];

    ll p[n + 1] = {0};
    for(int i = 1; i <= n; i++)
        p[i] = p[i - 1] + a[i] - k;

    unordered_map<ll, int> mp;
    mp[0] = 1;

    ll res = 0;
    for(int i = 1; i <= n; i++){
        res += mp[p[i]];
        mp[p[i]]++;
    }
    cout<<res;
    return 0;
}