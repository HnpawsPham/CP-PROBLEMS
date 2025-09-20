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

    int n;
    cin>>n;
    pii a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i].fi>>a[i].se;

    queue<int> q;
    bool check[n + 1] = {0};
    vi g[n + 1];

    for(int i = 1; i <= n; i++)
        if(a[i].fi == 0 && a[i].se == 0) {
            check[i] = 1;
            q.push(i);
        }
        else{
            if(a[i].fi != 0) g[a[i].fi].push_back(i);
            if(a[i].se != 0) g[a[i].se].push_back(i);
        }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : g[u]){
            if(check[v]) continue;
            check[v] = 1;
            q.push(v);
        }
    }
    cout<<accumulate(check + 1, check + n + 1, 0);
    return 0;
}