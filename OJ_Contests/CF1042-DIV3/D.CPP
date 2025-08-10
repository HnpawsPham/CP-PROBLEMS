#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int t, n;

void sol(){
    vector<vi> a(n + 1);
    int in[n + 1] = {0};

    for(int i = 1; i < n; i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
        in[u]++;
        in[v]++;
    }

    int cntleave = 0;
    bool isleave[n + 1] = {0};

    for(int i = 1; i <= n; i++){
        if(in[i] == 1){
            cntleave++;
            isleave[i] = 1;
        }
    }

    int res = 0;
    for(int i = 1; i <= n; i++){
        int tmp = 0;
        if(isleave[i]) tmp++;

        for(int v : a[i]){
            if(isleave[v]) tmp++;
        }
        res = max(res, tmp);
    }
    cout<<cntleave - res<<el;
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        sol();
    }

    return 0;
}