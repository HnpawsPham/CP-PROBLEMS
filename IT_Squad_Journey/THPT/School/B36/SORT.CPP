#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define vi vector<int>
#define fi first
#define se second

int n, q;
const int maxn = 1e5 + 5;
const ll oo = LLONG_MAX;
ll t[maxn * 4];

void update(int i, int l, int r, int pos, int val){
    if(l == r) {
        t[i] = val;
        return;
    }
    
    int mid = (l + r) / 2;
    if(pos <= mid) update(2 * i, l, mid, pos, val);
    else update(2 * i + 1, mid + 1, r, pos, val);

    t[i] = t[2 * i] + t[2 * i + 1];
    return;
}

ll query(int i, int st, int en, int l, int r){
    if(st > r || en < l) return 0;
    if(st >= l && en <= r) return t[i];
    
    int mid = (st + en) / 2;
    return query(2 * i, st, mid ,l , r) + query(2 * i + 1, mid + 1, en, l, r);
}

ll calc(int st, int en){
    if(st == en) return 0;
    int l = min(st, en), r = max(st, en);
    return query(1, 1, n, l, r);
}

int main(){
    // freopen("SORT.INP", "r", stdin);
    // freopen("SORT.OUT", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vi a(n + 1);
    int w[n];
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i < n; i++) cin>>w[i];

    vi tmp = a;
    sort(tmp.begin(), tmp.end());
    unordered_map<int, int> mp;

    for(int i = 1; i <= n; i++)
        mp[tmp[i]] = i;

    for(int i = 1; i < n; i++) 
        update(1, 1, n, i, w[i]);

    ll cost = 0;
    for(int i = 1; i <= n; i++)
        cost += calc(i, mp[a[i]]);

    cout<<cost<<el;

    cin>>q;
    while(q--){
        int opt, x, y;
        cin>>opt>>x>>y;

        if(opt == 1){
            cost -= calc(x, mp[a[x]]);
            cost -= calc(y, mp[a[y]]);

            swap(a[x], a[y]);

            cost += calc(x, mp[a[x]]);
            cost += calc(y, mp[a[y]]);
        }
        else{
            ll prev = query(1, 1, n, x, x);

            for (int i = 1; i <= n; ++i) {
                int target = mp[a[i]];
                if (min(i, mp[a[i]]) <= x && x < max(i, mp[a[i]])) {
                    cost -= prev;
                    cost += y;
                }
            }
            w[x] = y;
            update(1, 1, n, x, y);
        }
        cout<<cost<<el;
    }
    return 0;
}

