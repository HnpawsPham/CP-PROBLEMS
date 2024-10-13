#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int n, m, t;
const int maxn = 1005;
int a[maxn][maxn];

void solve(int u, int d){
    int res = 0;

    for(int i = u; i < d;i++){
        
    }

    cout<<res<<el;
    return;
}

int main(){
    freopen(".\\txt\\REC.INP" ,"r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    for(int i = 1; i<=n;i++)
        for(int j = 1; j<=m;j++) cin>>a[i][j];
    cin>>t;

    while(t--){
        int u, d;
        cin>>u>>d;
        solve(u, d);
    }

    return 0;
}