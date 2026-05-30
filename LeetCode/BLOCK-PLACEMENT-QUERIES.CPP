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
const int maxn = 15e4 + 5;
int t[maxn * 4];

void update(int i, int l, int r, int pos, int val){
    if(l == r){
        t[i] = val;
        return;
    }

    int mid = (l + r) / 2;
    if(pos <= mid) update(2 * i, l, mid, pos, val);
    else update(2 * i + 1, mid + 1, r, pos, val);
    t[i] = max(t[2 * i], t[2 * i + 1]);
}

int query(int i, int st, int en, int l, int r){
    if(st > r || en < l) return 0;
    if(st >= l && en <= r) return t[i];

    int mid = (st + en) / 2;
    return max(query(2 * i, st, mid, l, r), query(2 * i + 1, mid + 1, en, l, r));
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
    cin>>m;
    vector<vi> q;
    while(m--){
        int opt, x;
        cin>>opt>>x;
        vi v = {opt, x};

        if(opt == 1)
            q.push_back(v);
        else{
            int sz;
            cin>>sz;
            v.push_back(sz);
            q.push_back(v);
        }
    }

    for(const vi & v : q)
        n = max(n, v[1]);

    set<int> s;
    s.insert(0);
    s.insert(n + 1);

    vector<bool> res;
    for(const vi& v : q){
        auto it = s.upper_bound(v[1]);
        int prev = *std::prev(it);
        
        if(v[0] == 1){
            s.insert(v[1]);
            update(1, 1, n, v[1], v[1] - prev);
            
            if(*it <= n)
                update(1, 1, n, *it, *it - v[1]);
        }
        else{
            int ret = max(query(1, 1, n, 1, prev), v[1] - prev);
            if(ret >= v[2]) res.push_back(1);
            else res.push_back(0);
        }
    }

    for(bool x : res) cout<<x<<" ";
    return 0;
}

// 4
// 1 2
// 2 3 3
// 2 3 1
// 2 2 2