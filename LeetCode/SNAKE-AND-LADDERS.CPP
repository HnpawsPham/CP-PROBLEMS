n#include <bits/stdc++.h>
using namespace std;
#define el "\n"
#define vi vector<int>
#define pii pair<int, int>

int n;
vector<vi> t;
vi dis;
vector<pii> a;

void bfs(int st){
    queue<int> q;
    q.push(st);
    dis[st] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int next = u + 1; next < min(u + 7, n * n); next++){
            auto [i, j] = a[next];
            int v = (t[i][j] == -1 ? next : t[i][j] - 1);

            if(dis[v] == -1){
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    t.resize(n, vi(n));
    dis.assign(n * n, -1);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) cin>>t[i][j];

    // boustrophedon style
    for(int i = n - 1; i >= 0; i--){
        if((n - i - 1) % 2) 
            for(int j = n - 1; j >= 0; j--)
                a.push_back({i, j});
        
        else for(int j = 0; j < n; j++)
            a.push_back({i, j});
    }
    // for(auto x : a) cout<<"("<<x.first<<", "<<x.second<<")"<<el;

    bfs(0);
    cout<<dis[n * n - 1];
    return 0;
}