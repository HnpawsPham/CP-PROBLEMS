#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int v1, c1, v2, c2;
    cin >> v1 >> c1 >> v2 >> c2;

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int cnt = 0, res = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > v1) return cout<<-1, 0;
        if (a[i] > v2)  res += c1;
        else cnt++;
    }

    res += 1LL * (cnt / 2) * 2 * c2;

    if (cnt % 2 == 1)  res += c1;
    cout<<res;
    return 0;
}