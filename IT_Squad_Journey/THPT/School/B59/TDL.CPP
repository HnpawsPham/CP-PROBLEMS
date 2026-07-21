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
#define taskname "TDL"

int n, m, root[2];
const int maxn = 1e5 + 5;
vi a[maxn];

namespace sub2{
    int dfs(int u, int parent){
        vi tmp;
        for(int v : a[u]){
            if(v == parent) continue;
            tmp.push_back(dfs(v, u));
        }   

        sort(tmp.rbegin(), tmp.rend());
        int res = 0;
        for(int i = 0; i < tmp.size(); i++)
            res = max(res, tmp[i] + i + 1);
        return res;
    }

    int sol(){
        return dfs(root[0], -1);
    }
}


namespace sub3{
    bool gr[maxn];

    int dfs(int u, int parent){
        vi tmp;
        for(int v : a[u]){
            if(v == parent || gr[v] != gr[u]) continue;
            tmp.push_back(dfs(v, u));
        }   

        sort(tmp.rbegin(), tmp.rend());
        int res = 0;
        for(int i = 0; i < tmp.size(); i++)
            res = max(res, tmp[i] + i + 1);
        return res;
    }

    vi bfs(int st){
        queue<int> q;
        vi dis(n + 1, maxn * 2);
        q.push(st);
        dis[st] = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();

            for(int v : a[u]){
                if(dis[v] > dis[u] + 1){
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
        return dis;
    }

    int sol(){
        vi dis1 = bfs(root[0]), dis2 = bfs(root[1]);
        for(int i = 1; i <= n; i++){
            if(dis1[i] > dis2[i]) gr[i] = 1;
            else gr[i] = 0;
        }
        return max(dfs(root[0], -1), dfs(root[1], -1));
    }
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
    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    cin>>m;
    for(int i = 0; i < m; i++) cin>>root[i];

    if(m == 1)
        cout<<sub2::sol();
    else cout<<sub3::sol();
    return 0;
}