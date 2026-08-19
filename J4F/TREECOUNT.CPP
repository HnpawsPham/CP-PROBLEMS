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
const int maxn = 1e5 + 5;
int t[maxn], val[maxn], res[maxn];
vi a[maxn];

void add(int i, int val){
    while(i <= n){
        t[i] += val;
        i += (i & -i);
    }
}

int query(int i){
    int res = 0;
    while(i > 0){
        res += t[i];
        i -= (i &-i);
    }
    return res;
}

int query(int l, int r){
    if(l > r) return 0;
    return query(r) - query(l - 1);
}

void dfs(int u, int parent){
    int prev = query(val[u] + 1, n);
    
    for(int v : a[u]){
        if(v == parent) continue;
        dfs(v, u);
    }

    res[u] = query(val[u] + 1, n) - prev; 
    add(val[u], 1);
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
    vi v;
    for(int i = 1; i <= n; i++){
        cin>>val[i];
        v.push_back(val[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    for(int i = 1; i <= n; i++)
        val[i] = lower_bound(v.begin(), v.end(), val[i]) - v.begin() + 1;

    for(int v = 2; v <= n; v++){
        int u;
        cin>>u;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    memset(t, 0, sizeof t);
    memset(res, 0, sizeof res);
    
    dfs(1, 0);
    for(int i = 1; i <= n; i++)
        cout<<res[i]<<el;
    return 0;
}