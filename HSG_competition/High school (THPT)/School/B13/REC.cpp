#include <bits/stdc++.h>
using namespace std;
#define el '\n'

int n, m, t, res = 0;
const int maxn = 1005;
int a[maxn][maxn];

void solve (int h, int w, int x){
    for(int i = 1; i <= h;i++){
        for(int j = 1; j <=w; j++){
            if (abs(x - a[i][j]) > 1) return;
            res = max(res, i * j);
        }
    }
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

        for(int i = u; i <= d;i++){
            for(int j = 1; j <=m;j++){
                solve(i, j, a[i][j]);
            }
        }
        cout<<res<<el;
        res = 0;
    }

    return 0;
}