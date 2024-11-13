#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
const int maxn = (int)1e5 + 5;
int subsz[maxn], del[maxn];
vector<vector<int>> a(maxn);

void getSubsz(int u, int parent){
    subsz[u] =1;
    
    for(int v : a[u]){
        if(v == parent || del[v]) continue;
        getSubsz(v, u);
        subsz[u] += subsz[v];
    }
    return;
}

int getCen(int u, int parent, int n){
    for(int v : a[u]){
        if(v != parent && subsz[v] > n / 2 && !del[v]) 
        return getCen(v, u, n);
    }
    return u;
}

void dcp(int u){
    getSubsz(u, 0);
    int cen = getCen(u, 0, subsz[u]);
    del[cen] = 1;

    cout<<cen<<" ";

    for(int v : a[cen])
        if(!del[v]) dcp(v);
    return;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i = 1; i < n;i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dcp(1);

    return 0;
}