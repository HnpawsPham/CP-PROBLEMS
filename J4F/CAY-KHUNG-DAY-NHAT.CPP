#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct line {
    int u, v;
    ll w;
    line(int u1, int v1, ll w1) : u(u1), v(v1), w(w1) {}
    bool operator<(const line& other) const {
        return w < other.w;
    }
};

int n, m, component;
const int maxn = 1005;
const ll oo = 3e9;
vector<line> a;
int parent[maxn], sz[maxn];

void make_set(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
    return;
}

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

bool union_set(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return 0;
    if (sz[a] < sz[b]) swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
    component--;

    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    if (m < n - 1) 
        return cout << "NOT FOUND", 0;

    vector<line> a;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a.emplace_back(u, v, w);
    }

    sort(a.begin(), a.end());
    ll res = oo;

    for (int i = 0; i < m; ++i) {
        make_set();

        int msize = 0;
        for (int j = i; j < m; ++j) {
            if (union_set(a[j].u, a[j].v)) 
                msize++;
            
            if (msize == n - 1 && component == 1) {
                res = min(res, a[j].w - a[i].w);
                break;
            }
        }
    }

    if (res == oo) cout << "NOT FOUND";
    else cout << res;

    return 0;
}
