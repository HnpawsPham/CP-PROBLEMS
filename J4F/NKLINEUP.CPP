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
const int maxn = 5e4 + 5;
const int oo = 1e6 + 15;
int a[maxn], tmin[maxn * 4], tmax[maxn * 4];

void build(int i, int l, int r){
    if(l == r){
        tmin[i] = tmax[i] = a[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    tmin[i] = min(tmin[2 * i], tmin[2 * i + 1]);
    tmax[i] = max(tmax[2 * i], tmax[2 * i + 1]);
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

    cin>>n>>q;
    for(int i = 1; i <= n; i++) cin>>a[i];

    build(1, 1, n);
    while(q--){
        int l, r;
        cin>>l>>r;
        cout<<querymax(1, 1, n, l, r) - querymin(1, 1, n, l, r)<<el;
    }
    return 0;
}