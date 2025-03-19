#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;
const int maxn = 1e5 + 5;
ll k;
ll a[maxn];

int main(){
    freopen("LUCKY.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>a[i];

    int res = 0;
    for(int i = 0; i < n; i++){
        int d = ((a[i] == k / 2) && (k % 2 == 0));
        res = res + upper_bound(a, a + n, 1LL * k - a[i]) - lower_bound(a, a + n, 1LL * k - a[i]) - d;
    }
    cout<<res / 2;

    return 0;
}