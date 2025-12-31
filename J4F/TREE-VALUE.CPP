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
int bit[maxn], res[maxn], val[maxn];
vi a[maxn];

void update(int i, int val){
    while(i > 0){
        bit[i] += val;
        i -= (i & -i);
    }
    return;
}

int query(int i){
    int res = 0;
    while(i <= n){
        res += bit[i];
        i += (i & -i);
    }
    return res;
}

void dfs(int u, int parent){
    res[u] = query(val[u] + 1);
    update(val[u], 1);

    for(int v : a[u]){
        if(v == parent) continue;
        dfs(v, u);
    }
    update(val[u], -1);
    return;
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
    vi w(n);
    for(int i = 0; i < n; i++){
        cin>>w[i];
        val[i + 1] = w[i];
    }

    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    memset(bit, 0, sizeof bit);
    sort(w.begin(), w.end());
    w.erase(unique(w.begin(), w.end()), w.end());

    for(int i = 1; i <= n; i++)
        val[i] = lower_bound(w.begin(), w.end(), val[i]) - w.begin();
    
    dfs(1, 0);
    for(int i = 1; i <= n; i++) cout<<res[i]<<" ";
    return 0;
}