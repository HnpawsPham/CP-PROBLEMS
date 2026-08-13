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

struct node{
    int p = 0, s = 0, maxlen = 0;
    char l, r;
    node(){};
    node(int p1, int s1, int maxlen1, char l1, char r1) : p(p1), s(s1), maxlen(maxlen1), l(l1), r(r1) {};
};

int n;
const int maxn = 1e5 + 5;
node t[maxn * 4];

void merge(int l, int r, node& parent, node& cl, node& cr){
    int mid = (l + r) / 2;

    parent.l = cl.l;
    parent.r = cr.r;
    parent.maxlen = max(cl.maxlen, cr.maxlen);
    parent.p = cl.p;
    parent.s = cr.s;

    if(cl.p == mid - l + 1 && cl.r == cr.l)
        parent.p += cr.p;

    if(cr.s == r - mid && cl.r == cr.l)
        parent.s += cl.s;

    if(cl.r == cr.l)
        parent.maxlen = max(parent.maxlen, cl.s + cr.p);
}

void build(int i, int l, int r, const string& s){
    if(l == r){
        t[i] = {1, 1, 1, s[l - 1], s[l - 1]};
        return;
    }

    int mid = (l + r) / 2;
    build(2 * i, l, mid, s);
    build(2 * i + 1, mid + 1, r, s);
    merge(l, r, t[i], t[2 * i], t[2 * i + 1]);
}

void update(int i, int l, int r, int pos, char val){
    if(l == r){
        t[i] = {1, 1, 1, val, val};
        return;
    }

    int mid = (l + r) / 2;
    if(pos <= mid) update(2 * i, l, mid, pos, val);
    else update(2 * i + 1, mid + 1, r, pos, val);

    merge(l, r, t[i], t[2 * i], t[2 * i + 1]);
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, replace;
    int m;
    cin>>s>>m>>replace;
    int id[m];
    for(int i = 0; i < m; i++) cin>>id[i];

    n = s.length();
    build(1, 1, n, s);

    vector<int> res;
    for(int i = 0; i < m; i++){
        update(1, 1, n, id[i] + 1, replace[i]);
        res.push_back(t[1].maxlen);
    }

    for(int x : res) cout<<x<<" ";
    return 0;
}

// babacc
// 3
// bcb 
// 1 3 3