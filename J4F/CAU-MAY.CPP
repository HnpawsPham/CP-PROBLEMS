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
const int maxn = 2e5 + 5;
unordered_set<int> s[maxn];
vi a[maxn];
int cnt[maxn] = {0};

void dfs(int u, int parent){
    for(int v : a[u]){
        if(v == parent) continue;
        dfs(v, u);

        if(s[u].size() < s[v].size()) swap(s[u], s[v]);
        s[u].insert(s[v].begin(), s[v].end());
    }
    cnt[u] = s[u].size();
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
    for(int i = 1; i <= n; i++){
        int x;
        cin>>x;
        s[i].insert(x);
    }

    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1, 0);

    for(int i = 1; i <= n; i++) 
        cout<<cnt[i]<<" ";
    return 0;
}