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
//#define taskname ""

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;
    char a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin>>a[i][j];

    vector<vi> px(n + 1, vi(m + 1, 0)), py = px;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            px[i][j] = px[i - 1][j] + px[i][j - 1] - px[i - 1][j - 1];
            py[i][j] = py[i - 1][j] + py[i][j - 1] - py[i - 1][j - 1];

            if(a[i - 1][j - 1] == 'X') px[i][j]++;
            else if(a[i - 1][j - 1] == 'Y')
                py[i][j]++;
        }

    int cnt = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(px[i][j] == py[i][j] && px[i][j] > 0) 
                cnt++;
    cout<<cnt;
    return 0;
}

// 2 3
// X Y .
// Y . .