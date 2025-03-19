#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define pii pair<int, int>

int n;

int main(){
    freopen(".\\txt\\DU-LICH.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    int res = 0;
    unordered_map<ll, int> mp;

    for(int i = 0;i<n;i++){
        ll l, r;
        cin>>l>>r;
        mp[l]++;
        mp[r]++;

        res = max(mp[l], res);
        res = max(mp[r] , res);
    }

    cout<<res<<el;

    return 0;
}