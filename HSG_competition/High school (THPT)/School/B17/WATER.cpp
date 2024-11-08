#include <bits/stdc++.h>
using namespace std;
#define el "\n"

int n, m, cnt = 0;
const int maxn = 1005;
int a[maxn][maxn];
int du[maxn][maxn];

int main(){
    freopen(".\\txt\\WATER.INP", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=m;j++) cin>>a[i][j];
        
    for(int j=1;j<=m;j++) a[0][j] = a[1][j];
    for(int i = 1;i<=n;i++) a[i][0] = a[i][1];

    int sum = 0;
    for(int j = 1;j<=m;j++){
        for(int i=1;i<n;i++){
            int t = max(a[i + 1][j], a[i][j]) - min(a[i][j], a[i + 1][j]);
            cout<<t<<" ";
            sum += t;
            du[i + 1][j] = t;
        }
        cout<<el;
    }
    cout<<el;

    for(int i = 1;i<=n;i++){
        for(int j = 1; j < m;j++){
            int t = max(a[i][j], a[i][j + 1]) - min(a[i][j], a[i][j + 1]);
            cout<<t<<" ";
            if(!du[i][j + 1]) sum += t;
        }
        cout<<el;
    }
    
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++) cout<<du[i][j]<<" ";
        cout<<el;
    }
        
    cout<<sum<<el;
    return 0;
}