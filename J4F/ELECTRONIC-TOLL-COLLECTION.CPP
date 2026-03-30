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

int tc = 1;
int n, m;

int sol(){
    cin>>n>>m;
    int a[n + 1];
    for(int i = 1; i <= n; i++) cin>>a[i];

    int cnt = 0;
    while(m--){
        int u, v;
        cin>>u>>v;
        
        if(abs(a[u] - a[v]) == 1 || abs(a[u] - a[v]) == 3)
            cnt++;
    }
    return cnt;
}

int main(){
    #ifdef taskname
        freopen(taskname".INP", "r", stdin);
        freopen(taskname".OUT", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>tc;
    while(tc--){
        cout<<sol()<<el;
    }
    return 0;
}

// 1
// 16 16
// 1 1 1 1 2 2 2 2 3 3 3 3 4 4 4 4
// 1 4
// 2 4
// 3 4
// 4 8
// 5 8
// 6 8
// 7 8
// 8 12
// 9 12
// 10 12
// 11 12
// 12 16
// 13 16
// 14 16
// 15 16
// 16 4
