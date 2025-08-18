#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int tc, n;

int sol(){
    cin>>n;
    int in[n + 1] = {0};
    vi a[n + 1];

    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        in[u]++;
        in[v]++;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    if(n <= 3) return 0;

    int cntleave = 0;
    for(int i = 1; i <= n; i++) 
        if(in[i] == 1) cntleave++;
    
    int d, res = n + 5;
    for(int u = 1; u <= n; u++){
        d = 0;
        for(int v : a[u])
            if(in[v] == 1) d++;
        res = min(res, cntleave - d);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }

    return 0;
}