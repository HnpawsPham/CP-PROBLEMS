#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second
//#define taskname ""

int n, q;
const int maxn = 3e5 + 5;
vi t[4 * maxn];
int a[maxn];

void build(int i, int l, int r){
    if(l == r){
        t[i] = {a[l]};
        return;
    }

    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    merge(t[2 * i].begin(), t[2 * i].end(), t[2 * i + 1].begin(), t[2 * i + 1].end(),
          back_inserter(t[i]));
    return;
}

int query(int i, int st, int en, int l, int r, int x){
    if(st > r || en < l) return 0;
    if(st >= l && en <= r)
        return t[i].end() - upper_bound(t[i].begin(), t[i].end(), x);

    int mid = (st + en) / 2;
    return query(2 * i, st, mid, l, r, x) + query(2 * i + 1, mid + 1, en, l, r, x);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i];
    build(1, 1, n);

    cin>>q;
    while(q--){
        int l, r, x;
        cin>>l>>r>>x;
        cout<<query(1, 1, n, l, r, x)<<el;
    }
    return 0;
}