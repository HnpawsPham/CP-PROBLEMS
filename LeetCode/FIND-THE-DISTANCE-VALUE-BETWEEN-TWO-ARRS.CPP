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

    int n, m, d;
    cin>>n>>m>>d;
    vi a(n), b(m);
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int j = 0 ;j < m; j++) cin>>b[j];

    int cnt = 0;
    for(const int& x: a){
        bool ok = 1;
        for(const int& y : b)
            if(abs(x - y) <= d){
                ok = 0;
                break;
            }
        cnt += ok;
    }
    cout<<cnt;
    return 0;
}

// 3 4 2
// 4 5 8
// 10 9 1 8