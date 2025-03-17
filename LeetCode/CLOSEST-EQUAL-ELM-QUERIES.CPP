#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O2,unroll-loops,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#define vi vector<int>
#define se second
#define pii pair<int, vi>

vi solveQueries(vi& a, vi& q) {
    int n = q.size(), sz = a.size();
    unordered_map<int, vi> mp;

    for (int i = 0; i < sz; i++)
        mp[a[i]].push_back(i);
    
    for (pii x : mp) {
        vi v = x.se;
        int m = v.size();

        if (m == 1) {
            a[v[0]] = -1;
            continue;
        }

        for (int i = 0; i < m; i++) {
            int f = v[(i + 1) % m], b = v[(i - 1 + m) % m];

            int forw = min((sz - v[i] - 1) + f + 1, abs(v[i] - f));
            int back = min(abs(b - v[i]), v[i] + (sz - b));

            a[v[i]] = min(back, forw);
        }
    }
    for (int i = 0; i < n; i++)
        q[i] = a[q[i]];

    return q;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin>>n>>m;
    vi a(n), q(m);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < m; i++) cin>>q[i];

    vi res = solveQueries(a, q);

    for (int x : res) 
        cout<<x<<" ";

    return 0;
}