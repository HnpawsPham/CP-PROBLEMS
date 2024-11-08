#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n;
const int maxn = (int)1e5 + 5;
vector<vector<int>> a(maxn);

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
    // HOC CENTROID OF TREE

    return 0;
}