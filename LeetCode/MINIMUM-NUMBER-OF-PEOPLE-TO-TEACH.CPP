#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m, k;

bool ok(const vi& a, const vi& b){
    for(const int& x : a)
        for(const int& y : b)
            if(x == y) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    vector<vi> lang(m), ed(k, vi(2));
    for(int i = 0; i < m; i++){
        int sz, x;
        cin>>sz;
        for(int j = 0; j < sz; j++){
            cin>>x;
            lang[i].push_back(x);
        }
    }
    for(int i = 0; i < k; i++) cin>>ed[i][0]>>ed[i][1];

    int cnt[505] = {0};
    bitset<505> check;
    int need = 0;

    for(const auto& q : ed){
        int u = q[0] - 1 , v = q[1] - 1;
        if(ok(lang[u], lang[v])) continue;

        if(!check[u]){
            check[u] = 1;
            for(int x : lang[u]) cnt[x]++;
            need++;
        }

        if(!check[v]){
            check[v] = 1;   
            for(int x : lang[v]) cnt[x]++;
            need++;
        }
    }
    int maxx = 0;
    for(int i = 1; i <= 500; i++)
        maxx = max(maxx, cnt[i]);

    cout<<need - maxx;
    return 0;
}

// 2 3 3
// 1 1
// 1 2
// 2 1 2
// 1 2
// 1 3
// 2 3

// 3 4 4
// 1 2
// 2 
// 1 3
// 2
// 1 2
// 1 3
// 1 4
// 1 2
// 3 4
// 2 3