#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n, m;
const int maxn = 3 * (int)1e5 + 5;
ll a[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    ll mean = 0;
    for(int i = 0;i<m;i++) {
        cin>>a[i];
        mean += a[i];
    }
    mean /= n;
    ll maxx = -1;

    for(int i = 0; i<m;i++){
        ll x = a[i] - mean;
        maxx = max(maxx, (x >= 0 ? x : a[i]));
    }
    cout<<maxx;
    return 0;
}