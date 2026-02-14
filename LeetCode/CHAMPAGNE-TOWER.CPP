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

    int n, x, y;
    cin>>n>>x>>y;

    db a[105][105];
    memset(a, 0, sizeof a);
    a[0][0] = n;
  
    for(int i = 1; i <= x; i++)
        for(int j = 0; j <= i; j++){
            if(a[i - 1][j] > 1)
                a[i][j] = (a[i - 1][j] - 1) / 2.0;

            if(j > 0 && a[i - 1][j - 1] > 1)
                a[i][j] += (a[i - 1][j - 1] - 1) / 2.0;
        }
    cout<<fixed<<setprecision(5)<<min(1.0, a[x][y]);
    return 0;
}

// 1 1 1
// 2 1 
// 100000009 33 17