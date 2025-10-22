#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m, k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>m;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    unordered_map<int, int> cnt;
    for(int x : a) cnt[x]++;
    sort(a.begin(), a.end());

    vector<ll> v;
    for(int x : a){
        v.push_back(x + k);
        v.push_back(x - k);
        v.push_back(x);
    }

    int res = 1;
    for(int x : v){
        int l = lower_bound(a.begin(), a.end(), (ll)x - k) - a.begin();
        int r = upper_bound(a.begin(), a.end(), (ll)x + k) - a.begin();
        int d = r - l - cnt[x];

        res = max(res, min(d, m) + cnt[x]);
    }
    cout<<res;
    return 0;
}

// 3 1 2
// 1 4 5

// 4 5 1
// 5 11 20 20