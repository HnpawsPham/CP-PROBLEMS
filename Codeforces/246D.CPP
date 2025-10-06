#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m;
const int maxn = 1e5 + 3;
unordered_set<int> a[maxn];
int c[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 1; i <= n; i++) cin>>c[i];

    while(m--){
        int u, v;
        cin>>u>>v;
        if(c[u] != c[v]){
            a[c[u]].insert(c[v]);
            a[c[v]].insert(c[u]);
        } 
    }

    int res = *min_element(c + 1, c + n + 1), maxx = -1;
    for(int i = 1; i < maxn; i++){
        int sz = a[i].size();
        if(sz == 0) continue;

        if(maxx < sz){
            maxx = sz;
            res = i;
        }
    }
    cout<<res;
    return 0;
}