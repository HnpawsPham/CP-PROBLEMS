#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define pii pair<ll, int>
#define fi first
#define se second

int n, k;
unordered_map<ll, int> mp;

int main(){
    freopen("H9DNBD.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    while(n--){
        ll x; cin>>x;
        mp[x]++;
    }

    int cnt = 0;
    ll s = 0;
    for(pii x : mp)
        if(x.se >= k){
            cnt++;
            s += x.fi;
        }
    cout<<cnt<<" "<<s;

    return 0;
}