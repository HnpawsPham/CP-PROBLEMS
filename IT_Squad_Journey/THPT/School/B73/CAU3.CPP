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
#define taskname "CAU3"

int n;
const int maxn = 1500 * 1500 + 5;
int a[maxn];

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    memset(a, 0, sizeof a);
    for(int i = 0; i < n * n; i++)
        cin>>a[i];

    unordered_map<int, int> mp;
    for(int i = 0; i < n * n; i++)
        mp[a[i]]++;

    ll sum = 0;
    for(const pii& x : mp)
        sum += 1LL * x.fi * 1LL * x.se;

    ll res = 0;
    for(int i = 0; i < n * n; i++)
        res = max(res, sum - 1LL * a[i] * 1LL * mp[a[i]]);
    cout<<res;
    return 0;
}

// 3
// 1 2 4 1 1 1 1 1 2