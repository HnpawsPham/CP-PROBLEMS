#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, m, t;
const int maxn = (int)1e5 + 5;
vector<vector<int>> a(maxn);
bool check[maxn];
vector<int> dis(maxn, 0);
vector<int> src;
queue<int> q;

void bfs(){
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : a[u])
            if(!check[v]){
                q.push(v);
                dis[v] = dis[u] + 1;
                check[v] = 1;
            }
    }
    return;
}

void multi_src(){
    for(int x : src){
        q.push(x);
        check[x] = 1;
    }

    bfs();

    for(int i = 1; i <= n; i++) cout<<i<<" "<<dis[i]<<el;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    while(m--){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    src.push_back(1);
    src.push_back(3);
    multi_src();
    // while(t--){
    //     int u, v;
    //     cin>>u>>v;
    // }

    return 0;
}