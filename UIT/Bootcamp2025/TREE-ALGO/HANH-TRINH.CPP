#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>

int n;
const int maxn = 2e5 + 5;
vi a[maxn];
int dis[maxn] = {0};

void dfs(int u, int parent){
    for(int v : a[u]){
        if(v == parent) continue;
        dis[v] = dis[u] + 1;
        dfs(v, u);
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    int mid;
    dfs(1, 0);
    int fi = -1, se = -1;
    for(int i = 2; i <= n; i++)
        if(dis[i] > fi){
            fi = dis[i];
            mid = i;
        }

    memset(dis, 0, sizeof dis);
    dfs(mid, 0);
    
    for(int i = 2; i <= n; i++)
        if(i != mid)
            se = max(dis[i], se);

    cout<<se;
    return 0;
}
