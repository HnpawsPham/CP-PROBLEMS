#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, s, t;
    cin>>n>>s>>t;

    vector<vi> que(n);
    for(int i = 0; i < n; i++){
        int m;
        cin>>m;
        for(int j = 0; j < m; j++){
            int x;
            cin>>x;
            que[i].push_back(x);
        }
    }

    if(s == t) return cout<<0, 0;

    vector<vi> a(n);
    unordered_map<int, unordered_set<int>> mp;

    for(int i = 0; i < n; i++)
        for(int v : que[i]){
            if(!mp[v].empty())
                for(int x : mp[v]) {
                    a[i].push_back(x);
                    a[x].push_back(i);
                }
            
            mp[v].insert(i);
        }

    queue<int> q;
    vi dis(n, -1);
    for(int x : mp[s]){
        dis[x] = 1;
        q.push(x);
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        if(mp[t].count(u)) return cout<<dis[u], 0;

        for(int v : a[u]){
            if(dis[v] == -1){
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    cout<<-1;
    return 0;
}

// 2 1 6
// 3
// 1 2 7
// 3
// 3 6 7

// 5 15 12
// 2
// 7 12
// 3
// 4 5 15
// 1
// 6
// 2
// 15 19
// 3
// 9 12 13