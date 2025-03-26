#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;
ll k;

int main(){
    freopen("DAYBIAN.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    ll p[n + 1], a[n + 1];
    p[0] = 0;

    for(int i = 1; i <= n; i++){
        cin>>a[i];
        p[i] = p[i - 1] + a[i];
    }

    int cnt = 0;
    unordered_map<ll, int> mp;

    for(int i = 1; i <= n; i++){
        int target = p[i] - k;

        if(mp[target]) cnt += mp[target];
        mp[p[i]]++;
    }
    cout<<cnt;
    return 0;
}