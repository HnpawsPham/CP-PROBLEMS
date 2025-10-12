#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define pii pair<int, int>
#define fi first
#define se second

int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    int a[n + 1][m + 1];
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <=m ;j++) cin>>a[i][j];

    ll res = 0;
    for(int i = 1; i <= n; i++){
        int sum = 0;
        for(int j = 1; j <= m; j++) sum += a[i][j];
        res += (1LL << sum) - 1;
        res += (1LL << (m - sum)) - 1;
    }

    for(int j = 1; j <= m; j++){
        int sum = 0;
        for(int i = 1; i <= n; i++) sum += a[i][j];
        res += (1LL << sum) - 1;
        res += (1LL << (n - sum)) - 1;
    }
    cout<<res - 1LL * n * m;
    return 0;
}