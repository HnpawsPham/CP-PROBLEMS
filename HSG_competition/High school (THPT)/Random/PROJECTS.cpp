#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"
#define pll pair<ll, ll>

int n;
const int maxn = 2 * (int)1e5 + 5;
vector<vector<pll>> a(maxn);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i =0;i<n;i++){
        ll l, r, w;
        cin>>l>>r>>w;
        a[l].push_back({r, w});
    }

    return 0;
}