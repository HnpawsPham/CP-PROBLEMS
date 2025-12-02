#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define el '\n'
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define fi first
#define se second

int n, m, x, y;
const int maxn = 55;
int p[maxn][maxn] = {0};

int sol(int x, int y){
    int res = n * m + 5;
    for(int i = 1; i + x - 1 <= n; i++)
        for(int j = 1; j + y - 1 <= m; j++){
            int i1 = i + x - 1;
            int j1 = j + y - 1;
            res = min(res, p[i1][j1] - p[i - 1][j1] - p[i1][j - 1] + p[i - 1][j - 1]);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    int a[n + 1][m + 1];
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) cin>>a[i][j];
    cin>>x>>y;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + a[i][j];

    cout<<min(sol(x, y), sol(y, x));
    return 0;
}

// 10 10
// 1 0 1 1 1 1 0 0 1 1
// 1 1 1 1 1 1 1 1 0 1
// 1 0 0 1 1 1 1 1 1 1
// 1 0 1 1 1 1 0 1 1 1
// 0 0 1 0 1 1 1 1 1 1
// 1 1 1 0 0 1 1 1 1 1
// 0 1 1 0 1 1 0 1 1 0
// 1 0 1 1 1 0 1 1 1 1
// 1 0 1 1 1 0 1 1 0 1
// 1 1 0 1 1 1 0 0 1 0