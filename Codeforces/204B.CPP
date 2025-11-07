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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    pii a[n];
    unordered_map<int, int> mp, front;
    for(int i = 0; i < n; i++) {
        cin>>a[i].fi>>a[i].se;
        mp[a[i].fi]++;
        front[a[i].fi]++;

        if(a[i].se != a[i].fi) 
            mp[a[i].se]++;
    }

    int res = n + 5, target = (n + 1) / 2;
    for(auto [x, cnt] : mp) 
        if(cnt >= target)
            res = min(res, max(0, target - front[x]));

    cout<<(res == n + 5 ? -1 : res);
    return 0;
}