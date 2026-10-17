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
int parent[maxn], sz[maxn];

bool comp(int a, int b){
    int x = a, y = b;
    int suma = 0, sumb = 0;
    while(x > 0){
        suma += x % 10;
        x /= 10;
    }

    while(y > 0){
        sumb += y % 10;
        y /= 10;
    }
    if(suma != sumb) return suma < sumb;
    return a < b; 
}

void makeset(){
    for(int i =0 ; i < n; i++){
        parent[i] = i;
        sz[i] = 1;
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
    if(sz[v] > sz[u]) swap(u, v);

    sz[u] += sz[v];
    parent[v] = u;
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
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++)
        mp[a[i]] = i;
    sort(a.begin(), a.end(), comp);

    makeset();
    int cnt = n;
    for(int i = 0; i < n; i++){
        if(unite(mp[a[i]], i))
            cnt--;
    }
    cout<<n - cnt;
    return 0;
}

// 4
// 18 43 34 16

// 2
// 37 100