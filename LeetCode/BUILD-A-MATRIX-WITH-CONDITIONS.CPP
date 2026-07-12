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

bool dfs(int u, const vector<vi>& a, vi& check, vi& topo){
    check[u] = 1;

    for(int v : a[u]){
        if(check[v] == 1) return 0;
        if(check[v] == 0){
            if(!dfs(v, a, check, topo)) 
            return 0;
        }
    }

    check[u] = 2;
    topo.push_back(u);
    return 1;
}

vi topo(int n, const vector<vi>& ed){
    vector<vi> a(n + 1);

    for(const vi& v: ed)
        a[v[0]].push_back(v[1]);

    vi check(n + 1, 0), topo;
    for(int i = 1; i <= n; i++)
        if(check[i] == 0){
            if(!dfs(i, a, check, topo)) return {};
        }
    reverse(topo.begin(), topo.end());
    return topo;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, r, c;
    cin>>n>>r>>c;
    vector<vi> row(r, vi(2)), col(c, vi(2));
    for(int i = 0; i < r; i++) cin>>row[i][0]>>row[i][1];
    for(int i = 0; i < c; i++) cin>>col[i][0]>>col[i][1];

    vi topoRow = topo(n, row), topoCol = topo(n, col);
    if(topoRow.empty() || topoCol.empty()) return 0;

    vector<vi> res(n, vi(n, 0));
     for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(topoRow[i] == topoCol[j])
                res[i][j] = topoRow[i];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout<<res[i][j]<<" ";
        cout<<el;
    }
    return 0;
}

// 3 2 2
// 1 2
// 3 2
// 2 1
// 3 2