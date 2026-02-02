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

int n;
const int maxn = 5e4 + 5;
vi t[maxn * 4];

void build(const vi& a, int i, int st, int en){
    if(st == en){
        t[i] = {a[st - 1]};
        return;
    }
    
    int mid = (st + en) / 2;
    build(a, 2 * i, st, mid);
    build(a, 2 * i + 1, mid + 1, en);
    merge(t[2 * i].begin(), t[2 * i].end(), t[2 * i + 1].begin(), t[2 * i + 1].end(), back_inserter(t[i]));
    return;
}

bool query(int i, int st, int en, int l, int r, int x){
    if(st > r || en < l) return 0;
    if(st >= l && en <= r) 
        return upper_bound(t[i].begin(), t[i].end(), x) != t[i].end();

    int mid = (st + en) / 2;
    return query(2 * i, st, mid, l, r, x) || query(2 * i + 1, mid + 1, en, l, r, x);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin>>n>>m;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    vector<vi> q(m, vi(2));
    for(int i = 0; i < m; i++)
        cin>>q[i][0]>>q[i][1];

    build(a, 1, 1, n);
    vi res;
    for(vi& v : q){
        if(v[1] < v[0]) swap(v[1], v[0]);

        if(v[0] == v[1]){
            res.push_back(v[0]);
            continue;
        }

        if(a[v[0]] < a[v[1]]){
            res.push_back(v[1]);
            continue;
        }

        int x = max(a[v[0]], a[v[1]]), st = v[1] + 1;
        int l = st, r = n, mid, ans = -1;
        c
        while(l <= r){
            mid = (l + r) / 2;
            if(query(1, 1, n, st, mid, x)){
                r = mid - 1;
                ans = mid;
            }
            else l = mid + 1;
        }
        res.push_back(max(-1, ans - 1));
    }

    for(int x : res) cout<<x<<" ";
    return 0;
}

// 6 5
// 6 4 8 5 2 7
// 0 1
// 0 3
// 2 4
// 3 4
// 2 2
