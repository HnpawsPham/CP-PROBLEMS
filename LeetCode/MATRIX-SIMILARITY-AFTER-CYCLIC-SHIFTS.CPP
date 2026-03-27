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

    int n, m, k;
    cin>>n>>m>>k;
    vector<vi> a(n, vi(m));
    for(int i = 0; i < n; i++)
        for(int j= 0; j < m; j++) cin>>a[i][j];

    if(k % m == 0) return cout<<1, 0;

    vector<vi> b = a;
    while(k--){
        for(int i = 0; i < n; i++){
            int tmp = b[i][0];
            for(int j = 1; j < m; j++)
                b[i][j - 1] = b[i][j];
            b[i][m - 1] = tmp; 
        }
    }
    cout<<(b == a);
    return 0;
}

// 3 3 4
// 1 2 3 
// 4 5 6
// 7 8 9

// 3 4 2
// 1 2 1 2
// 5 5 5 5
// 6 3 6 3

// 2 2 3
// 2 2 
// 2 2 