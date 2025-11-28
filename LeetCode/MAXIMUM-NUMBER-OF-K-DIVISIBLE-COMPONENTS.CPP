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

int k, cnt = 0;
const int maxn = 3e4 + 15;
int parent[maxn] = {-1};
vi a[maxn];

ll dfs(const vi& w, int u){
    ll sum = w[u];
    for(int v : a[u]){
        if(v == parent[u]) continue;
        parent[v] = u;
        sum = (sum + dfs(w, v)) % k;
    }

    if(sum % k == 0){
        cnt++;
        sum = 0;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n>>k;
    vector<vi> ed(n - 1, vi(2));
    for(int i = 0; i < n - 1; i++) cin>>ed[i][0]>>ed[i][1];
    vi w(n);
    for(int i = 0; i < n; i++) cin>>w[i];

    for(const vi& v : ed){
        a[v[0]].push_back(v[1]);
        a[v[1]].push_back(v[0]);
    }

    dfs(w, 0);
    cout<<cnt;
    return 0;
}

// 5 6
// 0 2
// 1 2
// 1 3
// 2 4
// 1 8 1 4 4

// 7 3
// 0 1
// 0 2
// 1 3
// 1 4
// 2 5
// 2 6
// 3 0 6 1 5 2 1