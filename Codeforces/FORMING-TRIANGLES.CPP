#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc;

ll sol(){
    int n;
    cin>>n;
    int a[n];
    map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        mp[a[i]]++;
    }

    ll res = 0;
    int smol = 0;

    for(auto [_, cnt] : mp){
        if(cnt >= 3) // nC3
            res += cnt * (cnt - 1) * (cnt - 2) / 6LL;
        if(cnt >= 2)
            res += cnt * (cnt - 1) / 2LL * smol;

        smol += cnt;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--) cout<<sol()<<el;
    return 0;
}

// 2
// 3
// 1 2 3
// 4
// 1 1 1 1