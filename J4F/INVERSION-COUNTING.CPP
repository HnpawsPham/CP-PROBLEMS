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

int n, q, m = 0, bsz = 1200;
const int maxn = 250005;
const int maxm = 505;
int bst[maxm], ben[maxm], bid[maxn];
int a[maxn];

const int maxsz = 5e4 + 5;
struct BIT{
    int t[maxsz];

    BIT(){
        memset(t, 0, sizeof t);
    }

    void add(int i, int val){
        while(i < maxsz){
            t[i] += val;
            i += (i & -i);
        }
    }

    int query(int i){
        int res = 0;
        while(i > 0){
            res += t[i];
            i -= (i & -i);
        }
        return res;
    }
};

vector<BIT> bit;
ll res = 0;

void addBIT(int pos, int val){
    if(a[pos] == val) return;

    ll del = 0;
    // outside block
    for(int i = 1; i < bid[pos]; i++){
        int sz =ben[i] - bst[i] + 1;
        del -= sz - bit[i].query(a[pos]);
        del += sz - bit[i].query(val);
    }

    for(int i = bid[pos] + 1; i <= m; i++){
        del -= bit[i].query(a[pos] - 1);
        del += bit[i].query(val - 1);
    }

    // inside block
    for(int i = bst[bid[pos]]; i < pos; i++){
        if(a[i] > a[pos]) del--;
        if(a[i] > val) del++;
    }

    for(int i = pos + 1; i <= ben[bid[pos]]; i++){
        if(a[i] < a[pos]) del--;
        if(a[i] < val) del++;
    }

    bit[bid[pos]].add(a[pos], -1);
    bit[bid[pos]].add(val, 1);
    a[pos] = val;
    res += del;
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
    BIT ori;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        res += i - 1 - ori.query(a[i]);
        ori.add(a[i], 1);
    }

    // while(bsz * bsz < n) bsz++;

    for(int i = 1; i <= n; i+=bsz){
        m++;
        bst[m] = i;
        ben[m] = min(n, i + bsz - 1);

        for(int j = bst[m]; j <= ben[m]; j++)
            bid[j] = m;
    }

    bit.resize(m + 1);
    for(int i = 1; i <= n; i++)
        bit[bid[i]].add(a[i], 1);

    cin>>q;
    while(q--){
        int pos, val;
        cin>>pos>>val;
        addBIT(pos, val);
        cout<<res<<el;
    }
    return 0;
}