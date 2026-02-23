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

int n, m, q;

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>q;
    int a[n + 2][m + 2];
    memset(a, 0, sizeof a);

    while(q--){
        int i, j, x, y;
        cin>>i>>j>>x>>y;
        a[i][j]++;
        a[i][y + 1]--;  
        a[x + 1][j]--;
        a[x + 1][y + 1]++;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            cout<<a[i][j]<<" ";
        }
        cout<<el;
    }
    return 0;
}