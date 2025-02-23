#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int n;
ll l, r;
const int maxn = 1e5 + 5;
ll a[maxn], p[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>l>>r;
    p[0] = 0;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        p[i] = p[i - 1] + a[i];
    }
    sort(p, p + n + 1);

    ll res = 0;
    for(int i = 1; i<=n; i++)
        res += upper_bound(p, p + i, p[i] - l) - lower_bound(p, p + i, p[i] - r);
    cout<<res;

    return 0;
}