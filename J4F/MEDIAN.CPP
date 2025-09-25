#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, q, m;
const int maxn = 1e5 + 5;
int a[maxn];
vi t[maxn * 4];

void build(int i, int l, int r){
    if(l == r){
        t[i] = {a[l]};
        return;
    }

    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    t[i].resize(t[2 * i].size() + t[2 * i + 1].size());
    merge(t[2 * i].begin(), t[2 * i].end(), t[2 * i + 1].begin(), t[2 * i + 1].end(), t[i].begin());
    return;
}

int query(int i, int st, int en, int l, int r, int val){
    if(st > r || en < l) return 0;
    if(st >= l && en <= r)
        return upper_bound(t[i].begin(), t[i].end(), val) - t[i].begin(); 

    int mid = (st + en) / 2;
    return query(2 * i, st, mid, l, r, val) + query(2 * i + 1, mid + 1, en, l, r, val);
}

int kth(int st, int en, int k){
    int l = 1, r = m, mid;
    while(l <= r){
        mid = (l + r) / 2;

        if(query(1, 1, n, st, en, mid) >= k)
            r = mid - 1;
        else l = mid + 1;
    }
    return l;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    vi v;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        v.push_back(a[i]);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i = 1; i <= n; i++)
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;

    m = v.size();
    build(1, 1, n);

    while(q--){
        int l, r;
        cin>>l>>r;
        cout<<v[kth(l, r, (r - l + 2) / 2) - 1]<<el;
    }
    return 0;
}

// 8 5
// 2 8 4 16 5 2 10 6
// 1 3
// 2 5
// 6 8
// 5 8
// 1 8