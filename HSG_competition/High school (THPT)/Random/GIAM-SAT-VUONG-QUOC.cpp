#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
const int maxn = (int)1e5 + 5;
vector<vector<int>> a(maxn);
int subsz[maxn];
char res[maxn];

int getSubsz(int u, int parent){
    int &sz = subsz[u];
    sz = 1;

    for(int v : a[u]){
        if(v == parent) continue;
        sz += getSubsz(v, u);
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

void calc(int cen, int val){
    cout<<char('A' + val)<<el;
    res[cen] = char('A' + val);
    if(cen > 1) calc(cen / 2, val + 1);
    if(cen * 2 <= n) calc(cen * 2, val + 1);
    return;
}

int main(){
    freopen(".\\txt\\GIAM-SAT-VUONG-QUOC.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i =1;i<n;i++){
        int u, v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    getSubsz(1, 0);
    int cen = getCen(1, 0);
    calc(cen, 0);

    for(int i =1;i<=n;i++) cout<<res[i]<<" ";

    return 0;
}