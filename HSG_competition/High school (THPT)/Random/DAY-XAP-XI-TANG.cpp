#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el "\n"

int n;
const int maxn = 3 * (int)1e5 + 5;
ll a[maxn], b[maxn], c[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i)
        c[i] = a[i] - i;

    sort(c, c + n);
    ll m;
    if (n % 2 == 0) 
        m = (c[n / 2 - 1] + c[n / 2]) / 2;
    else m = c[n / 2];
    
    for (int i = 0; i < n; ++i)
        b[i] = m + i;

    ll d = 0;
    for(int i=0; i<n; ++i)
        d += abs(a[i] - b[i]);

    cout<<d<<el;
    for(int i = 0; i < n; i++) cout<<b[i]<<" ";
    return 0;
}