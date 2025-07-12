#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pii pair<ll, char>
#define fi first
#define se second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    if (n <= 1LL) 
        return cout << 0, 0;

    vector<pair<ll, int>> p;

    for (ll i = 2; 1LL * i * i <= n; i++) {
        if (n % i == 0) {
            ll tmp = 0;
            while (n % i == 0) {
                tmp++;
                n /= i;
            }
            p.push_back({i, tmp});
        }
    }

    if (n > 1LL) 
        p.push_back({n, 1});

    cout << p.size();
    for (auto x : p) 
        cout << " " << x.fi << " " << x.se;
    return 0;
}