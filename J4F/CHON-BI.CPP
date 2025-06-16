#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define pii pair<int, int>
#define fi first
#define se second

int n, m;

int main(){
    freopen("chonbi.inp", "r", stdin);
    freopen("chonbi.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vector<pii> a;

    while(m--){
        int u, v;
        cin>>u>>v;
        a.push_back({v, u});
    }
    sort(a.begin(), a.end(), greater<pii>());

    int sum = 0, i = 0;
    while(n > 0){
        sum += a[i].fi * min(n, a[i].se); 
        n -= a[i].se;
        i++;
    }
    cout<<sum;
    return 0;
}