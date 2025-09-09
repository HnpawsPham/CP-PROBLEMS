#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

struct line{
    int u, v, w, id;
    line(int u1, int v1, int w1, int id1) : u(u1), v(v1), w(w1), id(id1) {}; 
};

bool comp(const line& a, const line& b){
    return a.w > b.w;
}

int n, m;
ll s, sum = 0;
const int maxn = 5e4 + 4;
int parent[maxn], sz[maxn];
vector<line> a;
bitset<100005> check;

void make_set(){
    for(int i = 1; i <= n; i++){
        sz[i] = 1;
        parent[i] = i;
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

void kruskal(){
    int msz = 0;
    ll d = 0;
    
    for(int i = 0; i < m; i++){
        if(msz == n - 1) break;
        if(unite(a[i].u, a[i].v)){
            d += a[i].w;
            check[a[i].id] = 1;
            msz++;
        }
    }

    ll k = sum - s;
    for(int i = 0; i < m && d < k; i++)
        if(!check[a[i].id]){
            check[a[i].id] = 1;
            d += a[i].w;
        }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>s;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        sum += w;
        a.push_back({u, v, w, i});
    }
    sort(a.begin(), a.end(), comp);
    make_set();
    kruskal();

    int cnt = 0;
    vi res;
    for(int i = 1; i <= m; i++)
        if(!check[i]){
            cnt++;
            res.push_back(i);
        }

    cout<<cnt<<el;
    for(int x : res) cout<<x<<" ";
    return 0;
}