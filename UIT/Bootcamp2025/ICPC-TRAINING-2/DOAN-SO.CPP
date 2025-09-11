#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

void sol() {
    int l = 1, r = 100;
    int ans = 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        cout << "? " << mid <<el;
        cout.flush();

        string rep;
        cin >> rep;

        if (rep == ">=") {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << "! " << ans <<el;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) sol();
    return 0;
}
