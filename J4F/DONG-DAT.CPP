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

int n, m, k;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    vi a[n + 1];

    while(m--){
        int u, v;
        cin>>u>>v;
        if(u == v) continue;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    queue<int> q;
    bool check[n + 1] = {0}, bad[n + 1] = {0};
    check[1] = 1;
    q.push(1);

    while(k--){
        int u;
        cin>>u;
        for(int v : a[u]) bad[v] = 1;
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : a[u])
            if(!check[v] && !bad[v]){
                q.push(v);
                check[v] = 1;
            }
    }           

    int res = n;
    for(int i = 1; i <= n; i++)
        res -= check[i];
    cout<<res;
    return 0;
}