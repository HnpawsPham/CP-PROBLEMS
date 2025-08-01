#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define el '\n'
#define vi vector<int>

int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    vi a(n);
    for(int i = 0; i < n; i++) cin>>a[i];

    unordered_map<int, vi> mp;
    for(int i = 0; i < n; i++)
        mp[a[i]].push_back(i);
    
    queue<int> q;
    vi dis(n, -1);
    q.push(0);
    dis[0] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : {u + 1, u - 1})
            if(v >= 0 && v < n && dis[v] == -1){
                dis[v] = dis[u] + 1;
                q.push(v);
            }

        for(int v : mp[a[u]])
            if(dis[v] == -1) {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        mp[a[u]].clear();
    }
    cout<<dis[n - 1];
    return 0;
}