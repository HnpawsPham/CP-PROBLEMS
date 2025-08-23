#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define fi first
#define se second
#define pii pair<int, int>

const int maxn = 1e5 + 5;
bitset<maxn> nprime;
vi p;

void sieve() {
    nprime[0] = nprime[1] = 0;
    for (int i = 2; i * i <= maxn; i++) {
        if (!nprime[i]) {
            for (int j = i * i; j <= maxn; j += i)
                nprime[j] = 1;
        }
    }
    for (int i = 2; i <= maxn; i++)
        if (!nprime[i]) p.push_back(i);
    return;
}

double gud(int x, int y) {
    auto it1 = lower_bound(p.begin(), p.end(), x);
    auto it2 = lower_bound(p.begin(), p.end(), y);

    vector<int> g1, g2;

    if (it1 != p.end()) g1.push_back(*it1);
    if (it1 != p.begin()) g1.push_back(*(it1 - 1));
    if (it2 != p.end()) g2.push_back(*it2);
    if (it2 != p.begin()) g2.push_back(*(it2 - 1));

    double res = 1e18;
    for (int px : g1) 
        for (int py : g2) {
            double dist = sqrt(1.0 * (x - px) * (x - px) + 1.0 * (y - py) * (y - py));
            res = min(res, dist);
        }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pii> pts(n);
    for (int i = 0; i < n; i++) cin >> pts[i].fi >> pts[i].se;

    sieve();

    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++) {
        double d = gud(pts[i].fi, pts[i].se);
        cout << d << " ";
    }
    return 0;
}
