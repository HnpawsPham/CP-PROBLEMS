#include <bits/stdc++.h>
using namespace std;
#define el "\n"

const int maxn = 2 * (int)1e5 + 5;
int n;
vector<vector<int>> a(maxn);
int subsz[maxn];

int getSubSz(int u, int parent){
    int &sz = subsz[u];
    sz = 1;
    
    for(int v : a[u]){
        if(v == parent) continue;
        sz += getSubSz(v, u);
    }
    return sz;
}

int getCen(int u, int parent){
    for(int v : a[u]){
        if(v == parent) continue;
        if(subsz[v] * 2 > n) return getCen(v, u);
    }
    return u;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(); cout.tie();

    cin>>n;
    for(int i=1;i<n;i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    getSubSz(1, 0);
    cout<<getCen(1, 0)<<el;

    return 0;
}