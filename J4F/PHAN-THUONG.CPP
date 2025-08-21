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

    int n, k;
    cin>>n>>k;
    int a[n + 1][n + 1];
    for(int i = 1; i <= n; i++)  
        for(int j = 1; j <= n; j++) cin>>a[i][j];

    int p[n + 1][n + 1];
    p[0][0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            p[i][j] = p[i][j - 1] + p[i - 1][j] - p[i - 1][j - 1] + a[i][j];
    
    int res = 0;
    for(int i = k; i <= n; i++)
        for(int j = k; j <= n; j++)
            res = max(res, p[i][j] + p[i - k][j - k] - p[i][j - k] - p[i - k][j]);
    cout<<res;
    return 0;
}