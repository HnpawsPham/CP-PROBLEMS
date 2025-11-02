#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

struct item {
    int w, v, p, q;
    item(int w1 = 0, int v1 = 0, int p1 = 0, int q1 = 0) : w(w1), v(v1), p(p1), q(q1) {};

    bool operator<(const item& other) const {
        if (w != other.w) return w < other.w;
        if (v != other.v) return v < other.v;
        if (p != other.p) return p < other.p;
        return q < other.q;
    }
};

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    item a[n + 1];
    for(int i = 1; i <= n; i++) 
        cin>>a[i].w>>a[i].v>>a[i].p>>a[i].q;

    ll dp[m + 1] = {0};
    set<item> check;

    for(int i = 1; i <= n; i++){
        if(check.find(a[i]) != check.end()) continue;
        int cnt = 1;
        while((ll)a[i].v > 1LL * a[i].p * cnt) 
            cnt++;
        check.insert(a[i]);

        for(int j = m; j >= a[i].w; j--)
            dp[j] = max(dp[j], dp[j - a[i].w] + 1LL * cnt * a[i].v - 1LL * a[i].p * cnt + a[i].q);
    }
    cout<<*max_element(dp + 1, dp + m + 1);
    return 0;
}

// 1 20
// 5 20 5 3

// 3 10
// 5 6 2 3
// 2 4 2 1
// 5 2 3 2