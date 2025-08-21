#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc, n, m, q;
const int maxn = 2e5 + 5;
ll pa[maxn + 1] = {0}, pb[maxn + 1] = {0};
const ll oo = 1e16;

ll best(int x, int z){
    int y = z - x;
    if(x < 0 || x > n) return -oo;
    if(y < 0 || y > m) return -oo;
    return pa[x] + pb[y];
}

void sol(){
    cin>>n>>m>>q;
    int a[n + 1], b[m + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= m; i++) cin>>b[i];
    sort(a + 1, a + 1 + n, greater<int>());
    sort(b + 1, b + 1 + m, greater<int>());

    pa[0] = pb[0] = 0;
    for(int i = 1; i <= n; i++)
        pa[i] = pa[i - 1] + a[i];
    
    for(int i = 1; i <= m; i++)
        pb[i] = pb[i - 1] + b[i];

    while(q--){
        int x, y, z;
        cin>>x>>y>>z;

        int l = max({0, z - y, z - m});
        int r = min({z, x, n});

        while(r - l > 3){
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            if(best(m1, z) < best(m2, z)) l = m1;
            else r = m2;
        }

        ll res = 0;
        for(int i = l; i <= r; i++)
            res = max(res, best(i, z));
        cout<<res<<el;
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        sol();
    }

    return 0;
}