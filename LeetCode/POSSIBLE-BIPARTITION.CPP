#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>

int n, m;
vi color;
vector<vi> a;

bool dfs(int u){
    for(const int& v : a[u]){
        if(color[v] == -1){
            color[v] = 1 - color[u];
            if(!dfs(v)) return 0;
        }

        else if(color[v] == color[u]) return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vector<vi> t;
    while(m--){
        int u, v;
        cin>>u>>v;
        t.push_back({u, v});
    }

    a.resize(n + 1);
    for(const vi& v : t){
        a[v[0]].push_back(v[1]);
        a[v[1]].push_back(v[0]);
    }

    color.assign(n + 1, -1);

    for(int i = 1; i <= n; i++)
        if(color[i] == -1){
            color[i] = 0;

            if(!dfs(i))
                return cout<<0, 0;
        }
    cout<<1;
    return 0;
}