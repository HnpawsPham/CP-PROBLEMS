#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define pii pair<ll, int>
#define fi first
#define se second

int n, a, b;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>a>>b;

    vector<pii> pos;
    for(int i = 0; i < n; i++){
        ll x;
        int k;
        cin>>x>>k;
        pos.push_back({x, k});
    }

    sort(pos.begin(), pos.end());
    
    int p1[n + 1] = {0}, // cay tung
        p2[n + 1] = {0}; // cay truc

    for(int i = 1; i <= n; i++){
        int k = pos[i - 1].se;

        p1[i] = p1[i - 1] + (k == 1);
        p2[i] = p2[i - 1] + (k == 2);
    }

    int l = 1;
    ll res = LLONG_MAX;
    for(int r = 1; r <= n; r++){
        while(p1[r] - p1[l - 1] >= a && p2[r] - p2[l - 1] >= b){
            res = min(res, pos[r - 1].fi - pos[l - 1].fi);
            l++;
        }
    }
    cout<<(res != LLONG_MAX ? res : -1);

    return 0;
}