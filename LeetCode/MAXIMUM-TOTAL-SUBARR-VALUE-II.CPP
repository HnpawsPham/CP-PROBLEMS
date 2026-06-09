#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define piii pair<int, pii>
#define fi first
#define se second
//#define taskname ""

int n;
const int maxn = 5e4 + 4;
const int oo = 1e9 + 5;
int tmin[maxn * 4], tmax[maxn * 4];

void build(int i, int l, int r, const vi& a){
    if(l == r){
        tmin[i] = tmax[i] = a[l - 1];
        return;
    }

    int mid = (l + r) / 2;
    build(2 * i, l, mid, a);
    build(2 * i + 1, mid + 1, r, a);
    tmin[i] = min(tmin[2 * i], tmin[2 * i + 1]);
    tmax[i] = max(tmax[2 * i], tmax[2 * i + 1]);
    return;
}

int querymin(int i, int st, int en, int l, int r){
    if(st > r || en < l) return oo;
    if(st >= l && en <= r) return tmin[i];

    int mid = (st + en) / 2;
    return min(querymin(2 * i, st, mid, l, r), querymin(2 * i + 1, mid + 1, en, l, r));
}

int querymax(int i, int st, int en, int l, int r){
    if(st > r || en < l) return -oo;
    if(st >= l && en <= r) return tmax[i];

    int mid = (st + en) / 2;
    return max(querymax(2 * i, st, mid, l, r), querymax(2 * i + 1, mid + 1, en, l, r));
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin>>n>>k;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    
    build(1, 1, n, a);
    priority_queue<piii> pq;

    for(int i = 1; i <= n; i++)
        pq.push({querymax(1, 1, n, i, n) - querymin(1, 1, n, i, n), {i, n}});
    
    ll res = 0;
    while(k--){
        auto [val, pos] = pq.top();
        auto [l, r] = pos;
        res += val;
        pq.pop();

        if(r > l){
            r--;
            pq.push({querymax(1, 1, n, l, r) - querymin(1, 1, n, l, r), {l, r}});
        }
    }
    cout<<res;
    return 0;
}

// 3 2
// 1 3 2