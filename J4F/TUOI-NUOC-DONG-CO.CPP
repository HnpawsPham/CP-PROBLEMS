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

struct line{
    int u, v, w;
    line(){};
    line(int u1, int v1, int w1) : u (u1), v(v1), w(w1) {};

    bool operator<(const line& other) const{
        return w < other.w;
    }
};

int n;
const int maxn = 305;
vector<line> a;
int w[maxn], sz[maxn], parent[maxn];

void makeset(){
    for(int i = 1; i <= n; i++){
        sz[i] = 1;
        parent[i] = i;
    }
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

bool unite(int u, int v){
    u = find(u);
    v = find(v);

    if(u == v) return 0;
    if(sz[u] < sz[v]) swap(u, v);

    parent[v] = u;
    sz[u] += sz[v];
    return 1;
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
    for(int i = 1; i <= n; i++) cin>>w[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++){
            int x;
            cin>>x;
            if(i != j)
                a.push_back({i, j, x});
            else a.push_back({0, i, w[i]});
        }

    sort(a.begin(), a.end());
    int msz = 0, sum = 0;
    makeset();

    for(const line& x: a){
        if(unite(x.u, x.v)){
            sum += x.w;
            msz++;
        }
        if(msz == n) break;
    }
    cout<<sum;
    return 0;
}