#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, q;
const int maxn = 1e5 + 5;
const ll oo = LLONG_MAX;
int d[maxn], tmp[maxn];

ll calc(int u, int val, int v){
    return max(llabs(d[u] - val), llabs(val - d[v]));
}

void sub1(){
    while(q--){
        int u, v;
        cin>>u>>v;
        
        ll res = oo;
        for(int i = 1; i <= n; i++)
            res = min(res, calc(u, i, v));
        cout<<res<<el;
    }
    return;
}

void sol(){
    sort(tmp + 1, tmp + n + 1);

    while(q--){
        int u, v;
        cin>>u>>v;

        ll res = oo;
        ll mid = (d[u] + d[v] + 1) / 2;

        int pos = lower_bound(tmp + 1, tmp + n + 1, mid) - tmp;
        if(pos <= n) res = min(res, calc(u, tmp[pos], v));
        if(pos > 1) res = min(res, calc(u, tmp[pos - 1], v));
        cout<<res<<el;
    }
    return;
}

int main(){
    freopen("TRAVEL.INP", "r", stdin);
    freopen("TRAVEL.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    d[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin>>d[i];
        tmp[i] = d[i];
    }

    sol();
    // if(q <= 100) sub1();
    // else sol();
    return 0;
}