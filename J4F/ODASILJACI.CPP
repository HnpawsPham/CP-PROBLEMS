#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define piii pair<db, pii>
#define fi first
#define se second

int n;
const int maxn = 1005;
pii a[maxn];
int sz[maxn], parent[maxn];

void makeset(){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
    return;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool unite(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return 0;
    if(sz[a] < sz[b]) swap(a, b);

    sz[a] += sz[b];
    parent[b] = a;
    return 1;
}

db len(int i, int j){
    db x = a[i].fi - a[j].fi;
    db y = a[i].se - a[j].se;
    return sqrt(x * x + y * y);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i].fi>>a[i].se;
    makeset();

    vector<piii> ed;
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            ed.push_back({len(i, j), {i, j}});
    sort(ed.begin(), ed.end());

    db res = 0.0;
    int msz = 0;
    for(const auto& e : ed)
        if(unite(e.se.fi, e.se.se)){
            res = max(res, e.fi);
            if(++msz == n - 1) break;
        }    
    cout<<fixed<<setprecision(7)<<res / 2.0;
    return 0;
}