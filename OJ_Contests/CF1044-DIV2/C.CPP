#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc, n;

void query(int x, const vi& s) {
    cout << "? " << x << " " << s.size();
    for (int x : s) cout << " " << x;
    cout << el;
    cout.flush();
}

void res(const vi& path) {
    cout << "! " << path.size();
    for (int x : path) cout << " " << x;
    cout << el;
    cout.flush();
}

void sol() {
    cin >> n;
    vi dis(n + 1, 0);
    vi a(n);
    iota(a.begin(), a.end(), 1);

    for (int i = 1; i <= n; ++i) {
        query(i, a);
        cin >> dis[i];
    }

    int maxlen = 0, st = -1;
    for (int i = 1; i <= n; ++i) 
        if (dis[i] > maxlen) {
            maxlen = dis[i];
            st = i;
        }
    
    vi path;
    path.push_back(st);
    bool inpath[n + 1] = {0};
    inpath[st] = 1;

    while (path.size() < maxlen) {
        int cur = path.back();
        int gud = dis[cur] - 1;
        if (gud <= 0) break;

        vi tmp;
        for (int i = 1; i <= n; ++i) 
            if (!inpath[i] && dis[i] == gud) tmp.push_back(i);

        int next = -1;
        if (tmp.size() == 1) next = tmp[0];
        else {
            for (int x : tmp) {
                vi qs = {cur, x};
                query(cur, qs);

                int resp;
                cin >> resp;

                if (resp == 2) {
                    next = x;
                    break;
                }
            }
        }

        if (next == -1) break;
        path.push_back(next);
        inpath[next] = 1;
    }

    res(path);
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) 
        sol();
    return 0;
}
