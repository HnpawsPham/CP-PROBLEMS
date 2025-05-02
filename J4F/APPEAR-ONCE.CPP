#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define el "\n"

template<typename T>
using fast_map = gp_hash_table<T, int>;

int n;

int main(){
    // freopen("SDB.INP", "r", stdin);
    // freopen("SDB.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    vector<int> a(n);
    fast_map<int> cnt;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int res = 0;
    for (int x : a)
        if (cnt[x] == 1) res++;

    cout << res << el;
    for (int x : a)
        if (cnt[x] == 1) cout << x << el;

    return 0;
}
